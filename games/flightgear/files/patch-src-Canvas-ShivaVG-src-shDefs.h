--- src/Canvas/ShivaVG/src/shDefs.h.orig	2012-08-28 17:51:24.000000000 +0200
+++ src/Canvas/ShivaVG/src/shDefs.h	2012-08-28 17:52:06.000000000 +0200
@@ -34,7 +34,7 @@
 #include <math.h>
 #include <float.h>
 
-#ifndef VG_API_MACOSX
+#if !defined(VG_API_MACOSX) && !defined(__FreeBSD__)
 #  include <malloc.h>
 #endif
 
