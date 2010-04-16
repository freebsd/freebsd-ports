--- src/hawknl/hawknl/nlinternal.h.orig	2010-04-14 20:48:09.000000000 +0200
+++ src/hawknl/hawknl/nlinternal.h	2010-04-14 20:48:09.000000000 +0200
@@ -28,7 +28,7 @@
 
 /* for malloc and free */
 #include <stdlib.h>
-#ifndef MACOSX
+#if !defined(MACOS) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 
