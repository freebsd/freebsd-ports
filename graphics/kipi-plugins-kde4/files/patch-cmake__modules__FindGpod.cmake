--- ./cmake/modules/FindGpod.cmake.orig	2009-03-17 04:52:18.000000000 -0400
+++ ./cmake/modules/FindGpod.cmake	2009-06-08 04:36:50.000000000 -0400
@@ -24,7 +24,7 @@
 
   set(GPOD_DEFINITIONS ${PC_GPOD_CFLAGS_OTHER})
   
-  exec_program(${PKGCONFIG_EXECUTABLE} ARGS --atleast-version=0.7.0 libgpod-1.0 OUTPUT_VARIABLE _pkgconfigDevNull RETURN_VALUE GPOD_VERSION_OKAY)
+  exec_program(${PKG_CONFIG_EXECUTABLE} ARGS --atleast-version=0.7.0 libgpod-1.0 OUTPUT_VARIABLE _pkgconfigDevNull RETURN_VALUE GPOD_VERSION_OKAY)
 
 endif( NOT WIN32 )
 
