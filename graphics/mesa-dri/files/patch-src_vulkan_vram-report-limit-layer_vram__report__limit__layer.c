--- src/vulkan/vram-report-limit-layer/vram_report_limit_layer.c.orig	2026-04-15 14:20:41 UTC
+++ src/vulkan/vram-report-limit-layer/vram_report_limit_layer.c
@@ -447,7 +447,7 @@ vram_report_limit_CreateInstance(const VkInstanceCreat
    struct vram_report_limit_instance_data *instance_data = os_malloc_aligned(
       sizeof(*instance_data) + sizeof(instance_data->active_pdevices_array[0]) *
                                   active_pdevices_count,
-      CACHE_LINE_SIZE);
+      MESA_CACHE_LINE_SIZE);
    if (instance_data == NULL) {
       result = VK_ERROR_OUT_OF_HOST_MEMORY;
       goto err_free_is_pdevice_active_array;
