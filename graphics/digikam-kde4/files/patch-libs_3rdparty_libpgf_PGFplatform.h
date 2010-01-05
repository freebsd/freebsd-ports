--- libs/3rdparty/libpgf/PGFplatform.h.orig	2009-10-06 19:25:31.000000000 -0500
+++ libs/3rdparty/libpgf/PGFplatform.h	2009-10-06 19:25:43.000000000 -0500
@@ -306,7 +306,7 @@
 //-------------------------------------------------------------------------------
 // NetBSD
 //-------------------------------------------------------------------------------
-#ifdef __NetBSD__
+#if defined(__NetBSD__) || defined(__FreeBSD__)
 #ifndef __POSIX__ 
 #define __POSIX__ 
 #endif 
