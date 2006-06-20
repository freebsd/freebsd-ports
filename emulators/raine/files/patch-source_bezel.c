--- source/bezel.c.orig	Thu Nov 17 18:24:59 2005
+++ source/bezel.c	Thu Nov 17 18:49:28 2005
@@ -18,1 +18,1 @@
 #define __USE_ISOC99 1
 #include <math.h>
 
-#ifdef RAINE_DOS
+#if defined(RAINE_DOS) || __FreeBSD_version < 500300
 // djgpp seems to have specificities for rounding...
 // why on earth non one implements cleanly such basic function ???
 #define round rint
