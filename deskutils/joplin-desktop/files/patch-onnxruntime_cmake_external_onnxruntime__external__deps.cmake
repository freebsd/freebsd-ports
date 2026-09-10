--- onnxruntime/cmake/external/onnxruntime_external_deps.cmake.orig	2026-09-07 12:35:45 UTC
+++ onnxruntime/cmake/external/onnxruntime_external_deps.cmake
@@ -330,7 +330,7 @@ if (onnxruntime_ENABLE_CPUINFO)
   elseif (WIN32)
     set(CPUINFO_SUPPORTED TRUE)
   else()
-    if (onnxruntime_target_platform MATCHES "^(i[3-6]86|AMD64|x86(_64)?|armv[5-8].*|aarch64|arm64)$")
+    if (onnxruntime_target_platform MATCHES "^(i[3-6]86|AMD64|amd64|x86(_64)?|armv[5-8].*|aarch64|arm64)$")
       set(CPUINFO_SUPPORTED TRUE)
     else()
       message(WARNING "Target processor architecture \"${onnxruntime_target_platform}\" is not supported in cpuinfo.")
