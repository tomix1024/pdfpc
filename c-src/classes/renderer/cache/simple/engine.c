/* engine.c generated by valac 0.16.0, the Vala compiler
 * generated from engine.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gdk/gdk.h>


#define PDFPC_RENDERER_CACHE_TYPE_BASE (pdfpc_renderer_cache_base_get_type ())
#define PDFPC_RENDERER_CACHE_BASE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PDFPC_RENDERER_CACHE_TYPE_BASE, pdfpcRendererCacheBase))
#define PDFPC_RENDERER_CACHE_BASE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PDFPC_RENDERER_CACHE_TYPE_BASE, pdfpcRendererCacheBaseClass))
#define PDFPC_RENDERER_CACHE_IS_BASE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PDFPC_RENDERER_CACHE_TYPE_BASE))
#define PDFPC_RENDERER_CACHE_IS_BASE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PDFPC_RENDERER_CACHE_TYPE_BASE))
#define PDFPC_RENDERER_CACHE_BASE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PDFPC_RENDERER_CACHE_TYPE_BASE, pdfpcRendererCacheBaseClass))

typedef struct _pdfpcRendererCacheBase pdfpcRendererCacheBase;
typedef struct _pdfpcRendererCacheBaseClass pdfpcRendererCacheBaseClass;
typedef struct _pdfpcRendererCacheBasePrivate pdfpcRendererCacheBasePrivate;

#define PDFPC_METADATA_TYPE_BASE (pdfpc_metadata_base_get_type ())
#define PDFPC_METADATA_BASE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PDFPC_METADATA_TYPE_BASE, pdfpcMetadataBase))
#define PDFPC_METADATA_BASE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PDFPC_METADATA_TYPE_BASE, pdfpcMetadataBaseClass))
#define PDFPC_METADATA_IS_BASE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PDFPC_METADATA_TYPE_BASE))
#define PDFPC_METADATA_IS_BASE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PDFPC_METADATA_TYPE_BASE))
#define PDFPC_METADATA_BASE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PDFPC_METADATA_TYPE_BASE, pdfpcMetadataBaseClass))

typedef struct _pdfpcMetadataBase pdfpcMetadataBase;
typedef struct _pdfpcMetadataBaseClass pdfpcMetadataBaseClass;

#define PDFPC_RENDERER_CACHE_SIMPLE_TYPE_ENGINE (pdfpc_renderer_cache_simple_engine_get_type ())
#define PDFPC_RENDERER_CACHE_SIMPLE_ENGINE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PDFPC_RENDERER_CACHE_SIMPLE_TYPE_ENGINE, pdfpcRendererCacheSimpleEngine))
#define PDFPC_RENDERER_CACHE_SIMPLE_ENGINE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PDFPC_RENDERER_CACHE_SIMPLE_TYPE_ENGINE, pdfpcRendererCacheSimpleEngineClass))
#define PDFPC_RENDERER_CACHE_SIMPLE_IS_ENGINE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PDFPC_RENDERER_CACHE_SIMPLE_TYPE_ENGINE))
#define PDFPC_RENDERER_CACHE_SIMPLE_IS_ENGINE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PDFPC_RENDERER_CACHE_SIMPLE_TYPE_ENGINE))
#define PDFPC_RENDERER_CACHE_SIMPLE_ENGINE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PDFPC_RENDERER_CACHE_SIMPLE_TYPE_ENGINE, pdfpcRendererCacheSimpleEngineClass))

typedef struct _pdfpcRendererCacheSimpleEngine pdfpcRendererCacheSimpleEngine;
typedef struct _pdfpcRendererCacheSimpleEngineClass pdfpcRendererCacheSimpleEngineClass;
typedef struct _pdfpcRendererCacheSimpleEnginePrivate pdfpcRendererCacheSimpleEnginePrivate;
#define _g_mutex_free0(var) ((var == NULL) ? NULL : (var = (g_mutex_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _pdfpcRendererCacheBase {
	GObject parent_instance;
	pdfpcRendererCacheBasePrivate * priv;
	pdfpcMetadataBase* metadata;
};

struct _pdfpcRendererCacheBaseClass {
	GObjectClass parent_class;
	void (*store) (pdfpcRendererCacheBase* self, guint index, GdkPixmap* pixmap);
	GdkPixmap* (*retrieve) (pdfpcRendererCacheBase* self, guint index);
};

struct _pdfpcRendererCacheSimpleEngine {
	pdfpcRendererCacheBase parent_instance;
	pdfpcRendererCacheSimpleEnginePrivate * priv;
	GdkPixmap** storage;
	gint storage_length1;
	GMutex* mutex;
};

struct _pdfpcRendererCacheSimpleEngineClass {
	pdfpcRendererCacheBaseClass parent_class;
};


static gpointer pdfpc_renderer_cache_simple_engine_parent_class = NULL;

GType pdfpc_renderer_cache_base_get_type (void) G_GNUC_CONST;
GType pdfpc_metadata_base_get_type (void) G_GNUC_CONST;
GType pdfpc_renderer_cache_simple_engine_get_type (void) G_GNUC_CONST;
enum  {
	PDFPC_RENDERER_CACHE_SIMPLE_ENGINE_DUMMY_PROPERTY
};
pdfpcRendererCacheSimpleEngine* pdfpc_renderer_cache_simple_engine_new (pdfpcMetadataBase* metadata);
pdfpcRendererCacheSimpleEngine* pdfpc_renderer_cache_simple_engine_construct (GType object_type, pdfpcMetadataBase* metadata);
pdfpcRendererCacheBase* pdfpc_renderer_cache_base_construct (GType object_type, pdfpcMetadataBase* metadata);
guint pdfpc_metadata_base_get_slide_count (pdfpcMetadataBase* self);
static void pdfpc_renderer_cache_simple_engine_real_store (pdfpcRendererCacheBase* base, guint index, GdkPixmap* pixmap);
static GdkPixmap* pdfpc_renderer_cache_simple_engine_real_retrieve (pdfpcRendererCacheBase* base, guint index);
static void pdfpc_renderer_cache_simple_engine_finalize (GObject* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);


/**
         * Initialize the cache store
         */
pdfpcRendererCacheSimpleEngine* pdfpc_renderer_cache_simple_engine_construct (GType object_type, pdfpcMetadataBase* metadata) {
	pdfpcRendererCacheSimpleEngine * self = NULL;
	pdfpcMetadataBase* _tmp0_;
	GMutex* _tmp1_;
	pdfpcMetadataBase* _tmp2_;
	guint _tmp3_ = 0U;
	GdkPixmap** _tmp4_ = NULL;
	GMutex* _tmp5_;
	g_return_val_if_fail (metadata != NULL, NULL);
	_tmp0_ = metadata;
	self = (pdfpcRendererCacheSimpleEngine*) pdfpc_renderer_cache_base_construct (object_type, _tmp0_);
	_tmp1_ = self->mutex;
	g_mutex_lock (_tmp1_);
	_tmp2_ = ((pdfpcRendererCacheBase*) self)->metadata;
	_tmp3_ = pdfpc_metadata_base_get_slide_count (_tmp2_);
	_tmp4_ = g_new0 (GdkPixmap*, _tmp3_ + 1);
	self->storage = (_vala_array_free (self->storage, self->storage_length1, (GDestroyNotify) g_object_unref), NULL);
	self->storage = _tmp4_;
	self->storage_length1 = _tmp3_;
	_tmp5_ = self->mutex;
	g_mutex_unlock (_tmp5_);
	return self;
}


pdfpcRendererCacheSimpleEngine* pdfpc_renderer_cache_simple_engine_new (pdfpcMetadataBase* metadata) {
	return pdfpc_renderer_cache_simple_engine_construct (PDFPC_RENDERER_CACHE_SIMPLE_TYPE_ENGINE, metadata);
}


/**
         * Store a pixmap in the cache using the given index as identifier
         */
static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void pdfpc_renderer_cache_simple_engine_real_store (pdfpcRendererCacheBase* base, guint index, GdkPixmap* pixmap) {
	pdfpcRendererCacheSimpleEngine * self;
	GMutex* _tmp0_;
	GdkPixmap** _tmp1_;
	gint _tmp1__length1;
	guint _tmp2_;
	GdkPixmap* _tmp3_;
	GdkPixmap* _tmp4_;
	GdkPixmap* _tmp5_;
	GMutex* _tmp6_;
	self = (pdfpcRendererCacheSimpleEngine*) base;
	g_return_if_fail (pixmap != NULL);
	_tmp0_ = self->mutex;
	g_mutex_lock (_tmp0_);
	_tmp1_ = self->storage;
	_tmp1__length1 = self->storage_length1;
	_tmp2_ = index;
	_tmp3_ = pixmap;
	_tmp4_ = _g_object_ref0 (_tmp3_);
	_g_object_unref0 (_tmp1_[_tmp2_]);
	_tmp1_[_tmp2_] = _tmp4_;
	_tmp5_ = _tmp1_[_tmp2_];
	_tmp6_ = self->mutex;
	g_mutex_unlock (_tmp6_);
}


/**
         * Retrieve a stored pixmap from the cache.
         *
         * If no item with the given index is available null is returned
         */
static GdkPixmap* pdfpc_renderer_cache_simple_engine_real_retrieve (pdfpcRendererCacheBase* base, guint index) {
	pdfpcRendererCacheSimpleEngine * self;
	GdkPixmap* result = NULL;
	GdkPixmap** _tmp0_;
	gint _tmp0__length1;
	guint _tmp1_;
	GdkPixmap* _tmp2_;
	GdkPixmap* _tmp3_;
	self = (pdfpcRendererCacheSimpleEngine*) base;
	_tmp0_ = self->storage;
	_tmp0__length1 = self->storage_length1;
	_tmp1_ = index;
	_tmp2_ = _tmp0_[_tmp1_];
	_tmp3_ = _g_object_ref0 (_tmp2_);
	result = _tmp3_;
	return result;
}


static void pdfpc_renderer_cache_simple_engine_class_init (pdfpcRendererCacheSimpleEngineClass * klass) {
	pdfpc_renderer_cache_simple_engine_parent_class = g_type_class_peek_parent (klass);
	PDFPC_RENDERER_CACHE_BASE_CLASS (klass)->store = pdfpc_renderer_cache_simple_engine_real_store;
	PDFPC_RENDERER_CACHE_BASE_CLASS (klass)->retrieve = pdfpc_renderer_cache_simple_engine_real_retrieve;
	G_OBJECT_CLASS (klass)->finalize = pdfpc_renderer_cache_simple_engine_finalize;
}


static void pdfpc_renderer_cache_simple_engine_instance_init (pdfpcRendererCacheSimpleEngine * self) {
	GMutex* _tmp0_;
	self->storage = NULL;
	_tmp0_ = g_mutex_new ();
	self->mutex = _tmp0_;
}


static void pdfpc_renderer_cache_simple_engine_finalize (GObject* obj) {
	pdfpcRendererCacheSimpleEngine * self;
	self = PDFPC_RENDERER_CACHE_SIMPLE_ENGINE (obj);
	self->storage = (_vala_array_free (self->storage, self->storage_length1, (GDestroyNotify) g_object_unref), NULL);
	_g_mutex_free0 (self->mutex);
	G_OBJECT_CLASS (pdfpc_renderer_cache_simple_engine_parent_class)->finalize (obj);
}


/**
     * Cache store which simply holds all given items in memory.
     */
GType pdfpc_renderer_cache_simple_engine_get_type (void) {
	static volatile gsize pdfpc_renderer_cache_simple_engine_type_id__volatile = 0;
	if (g_once_init_enter (&pdfpc_renderer_cache_simple_engine_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (pdfpcRendererCacheSimpleEngineClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) pdfpc_renderer_cache_simple_engine_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (pdfpcRendererCacheSimpleEngine), 0, (GInstanceInitFunc) pdfpc_renderer_cache_simple_engine_instance_init, NULL };
		GType pdfpc_renderer_cache_simple_engine_type_id;
		pdfpc_renderer_cache_simple_engine_type_id = g_type_register_static (PDFPC_RENDERER_CACHE_TYPE_BASE, "pdfpcRendererCacheSimpleEngine", &g_define_type_info, 0);
		g_once_init_leave (&pdfpc_renderer_cache_simple_engine_type_id__volatile, pdfpc_renderer_cache_simple_engine_type_id);
	}
	return pdfpc_renderer_cache_simple_engine_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


