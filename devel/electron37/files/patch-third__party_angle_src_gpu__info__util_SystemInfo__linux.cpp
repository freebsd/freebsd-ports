--- third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp.orig	2022-02-23 19:25:59 UTC
+++ third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp
@@ -71,6 +71,24 @@ bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo
 
 bool GetSystemInfo(SystemInfo *info)
 {
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+    if (!CollectMesaCardInfo(&(info->gpus)))
+    {
+#if defined(__FreeBSD__)
+        if (!GetPCIDevicesFreeBSD(&(info->gpus)))
+        {
+#endif
+#if defined(ANGLE_USE_VULKAN_SYSTEM_INFO)
+            // Try vulkan backend to get GPU info
+            return GetSystemInfoVulkan(info);
+#else
+            return false;
+#endif
+#if defined(__FreeBSD__)
+        }
+#endif
+    }
+#else
     if (!GetPCIDevicesWithLibPCI(&(info->gpus)))
     {
 #if defined(ANGLE_USE_VULKAN_SYSTEM_INFO)
@@ -85,6 +103,7 @@ bool GetSystemInfo(SystemInfo *info)
     {
         return false;
     }
+#endif
 
     GetDualGPUInfo(info);
 
