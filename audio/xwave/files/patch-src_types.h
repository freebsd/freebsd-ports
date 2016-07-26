--- src/types.h.orig	1998-11-08 23:22:55 UTC
+++ src/types.h
@@ -27,7 +27,7 @@
 typedef unsigned char byte;
 typedef byte bool;
 
-#ifdef FreeBSD
+#ifdef __FreeBSD__
 typedef unsigned long ulong;
 #endif
 
