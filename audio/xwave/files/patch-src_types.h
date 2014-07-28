--- src/types.h.orig	Mon Nov  9 08:22:55 1998
+++ src/types.h	Fri Jun 30 19:49:19 2000
@@ -27,7 +27,7 @@
 typedef unsigned char byte;
 typedef byte bool;
 
-#ifdef FreeBSD
+#ifdef __FreeBSD__
 typedef unsigned long ulong;
 #endif
 
