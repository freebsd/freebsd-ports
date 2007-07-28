--- hidparser/hidtypes.h.orig	2007-07-16 12:21:55.000000000 +0300
+++ hidparser/hidtypes.h	2007-07-16 12:22:04.000000000 +0300
@@ -21,7 +21,7 @@
 typedef unsigned char  uchar;
 #endif
 
-#if HPUX || __APPLE__
+#if HPUX || __APPLE__ || __FreeBSD__
 typedef unsigned long  ulong;
 #endif
 
