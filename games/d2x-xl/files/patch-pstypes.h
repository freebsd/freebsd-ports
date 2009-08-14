--- include/pstypes.h.orig	2009-07-22 00:02:08.000000000 +0200
+++ include/pstypes.h	2009-07-22 00:03:47.000000000 +0200
@@ -28,7 +28,7 @@
 
 //define unsigned types;
 typedef unsigned char ubyte;
-#ifndef __unix__
+#ifdef __unix__
 typedef unsigned short ushort;
 typedef unsigned int uint;
 typedef unsigned long ulong;
