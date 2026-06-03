--- src/OpenCL.cpp.orig	2023-02-06 15:09:28 UTC
+++ src/OpenCL.cpp
@@ -787,7 +787,7 @@ OpenCL<net_t>::OpenCL(const int gpu, const bool silent
             bool preferred = (gpu == id);
 
             if (((this_score > best_score)
-                 && (d.getInfo<CL_DEVICE_TYPE>() != CL_DEVICE_TYPE_CPU))
+                 /*&& (d.getInfo<CL_DEVICE_TYPE>() != CL_DEVICE_TYPE_CPU)*/) // Do not reject CPU-only OpenCL providers because some users only have that (ex. pocl)
                 || preferred) {
                 best_version = opencl_version;
                 best_platform = p;
