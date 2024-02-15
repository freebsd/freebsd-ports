--- src/gallium/winsys/amdgpu/drm/amdgpu_bo.c.orig	2024-02-16 16:21:40 UTC
+++ src/gallium/winsys/amdgpu/drm/amdgpu_bo.c
@@ -709,7 +709,7 @@ struct pb_slab *amdgpu_bo_slab_alloc(void *priv, unsig
    slab_bo->slab.group_index = group_index;
    slab_bo->slab.entry_size = entry_size;
    slab_bo->entries = os_malloc_aligned(slab_bo->slab.num_entries * sizeof(*slab_bo->entries),
-                                        CACHE_LINE_SIZE);
+                                        MESA_CACHE_LINE_SIZE);
    if (!slab_bo->entries)
       goto fail;
 
