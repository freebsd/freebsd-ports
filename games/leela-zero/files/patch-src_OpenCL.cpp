--- src/OpenCL.cpp.orig	2019-06-12 22:15:19 UTC
+++ src/OpenCL.cpp
@@ -785,7 +785,7 @@ OpenCL<net_t>::OpenCL(int gpu, bool silent) {
             bool preferred = (gpu == id);
 
             if (((this_score > best_score)
-                 && (d.getInfo<CL_DEVICE_TYPE>() != CL_DEVICE_TYPE_CPU))
+                 /*&& (d.getInfo<CL_DEVICE_TYPE>() != CL_DEVICE_TYPE_CPU)*/) // Do not reject CPU-only OpenCL providers because some users only have that (ex. pocl)
                 || preferred) {
                 best_version = opencl_version;
                 best_platform = p;
