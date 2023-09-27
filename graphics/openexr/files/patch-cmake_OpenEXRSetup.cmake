--- cmake/OpenEXRSetup.cmake.orig	2023-09-25 02:46:06 UTC
+++ cmake/OpenEXRSetup.cmake
@@ -215,7 +215,7 @@ if(NOT TARGET PkgConfig::deflate AND NOT deflate_FOUND
   set(EXR_DEFLATE_LIB)
 else()
   set(EXR_DEFLATE_INCLUDE_DIR)
-  set(EXR_DEFLATE_LIB ${deflate_LIBRARIES})
+  set(EXR_DEFLATE_LIB ${deflate_LINK_LIBRARIES})
   # set EXR_DEFATE_LDFLAGS for OpenEXR.pc.in for static build
   if (BUILD_SHARED_LIBS)
     set(EXR_DEFLATE_LDFLAGS "")
