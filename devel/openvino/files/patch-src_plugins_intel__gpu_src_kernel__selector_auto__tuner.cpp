--- src/plugins/intel_gpu/src/kernel_selector/auto_tuner.cpp.orig	2026-04-10 01:28:44 UTC
+++ src/plugins/intel_gpu/src/kernel_selector/auto_tuner.cpp
@@ -228,7 +228,7 @@ TuningCache* TuningCache::get() {
     GetModuleFileName(hm, module_path, sizeof(module_path));
     std::string bin_path(module_path);
     path = bin_path.substr(0, bin_path.find_last_of("\\")) + "\\cache.json";
-#elif __linux__
+#elif __FreeBSD__
     const char* device_info_failed_msg = "Device lookup failed";
     Dl_info dl_info;
     dladdr((void*)(device_info_failed_msg), &dl_info);  // NOLINT
