https://github.com/Themaister/Granite/issues/133

--- ares/n64/vulkan/parallel-rdp/vulkan/device.cpp.orig	2024-08-11 00:29:27 UTC
+++ ares/n64/vulkan/parallel-rdp/vulkan/device.cpp
@@ -874,7 +874,7 @@ void Device::init_workarounds()
 		workarounds.emulate_event_as_pipeline_barrier = true;
 	}
 
-	if (ext.driver_id == VK_DRIVER_ID_NVIDIA_PROPRIETARY && gpu_props.driverVersion < VK_VERSION_MAJOR(535))
+	if (ext.driver_id == VK_DRIVER_ID_NVIDIA_PROPRIETARY)
 	{
 		LOGW("Disabling pipeline cache control.\n");
 		workarounds.broken_pipeline_cache_control = true;
