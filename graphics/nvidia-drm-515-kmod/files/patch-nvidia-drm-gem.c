--- nvidia-drm-gem.c.orig	2023-12-29 19:08:23 UTC
+++ nvidia-drm-gem.c
@@ -68,15 +68,7 @@ void nv_drm_gem_free(struct drm_gem_object *gem)
 #if !defined(NV_DRM_DRIVER_HAS_GEM_PRIME_CALLBACKS) && \
     defined(NV_DRM_GEM_OBJECT_VMAP_HAS_MAP_ARG)
 
-/*
- * The 'dma_buf_map' structure is renamed to 'iosys_map' by the commit
- * 7938f4218168 ("dma-buf-map: Rename to iosys-map").
- */
-#if defined(NV_LINUX_IOSYS_MAP_H_PRESENT)
-typedef struct iosys_map nv_sysio_map_t;
-#else
 typedef struct dma_buf_map nv_sysio_map_t;
-#endif
 
 static int nv_drm_gem_vmap(struct drm_gem_object *gem,
                            nv_sysio_map_t *map)
