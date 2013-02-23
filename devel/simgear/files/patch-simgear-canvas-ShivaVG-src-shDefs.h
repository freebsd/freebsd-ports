--- simgear/canvas/ShivaVG/src/shDefs.h.orig	2013-02-20 17:17:38.000000000 +0100
+++ simgear/canvas/ShivaVG/src/shDefs.h	2013-02-20 17:18:16.000000000 +0100
@@ -34,7 +34,7 @@
 #include <math.h>
 #include <float.h>
 
-#ifndef VG_API_MACOSX
+#if !defined(VG_API_MACOSX) && !defined(__FreeBSD__)
 #  include <malloc.h>
 #endif
 
