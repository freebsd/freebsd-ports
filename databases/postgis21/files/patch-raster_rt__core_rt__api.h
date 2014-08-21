--- raster/rt_core/rt_api.h.orig	2014-05-04 17:15:13 UTC
+++ raster/rt_core/rt_api.h
@@ -42,7 +42,7 @@
 #endif
 
 
-#if defined(__FreeBSD_kernel__) || defined(__OpenBSD__)    /* seems to work like Linux... */
+#if defined(__FreeBSD__) || defined(__DragonFly__)    /* seems to work like Linux... */
 #if !defined(LINUX)
 #define LINUX
 #endif
