--- src/hawknl/hawknl/htinternal.h.orig	2010-04-14 20:48:09.000000000 +0200
+++ src/hawknl/hawknl/htinternal.h	2010-04-14 20:48:09.000000000 +0200
@@ -27,7 +27,7 @@
 
 /* for malloc and free */
 #include <stdlib.h>
-#ifndef MACOSX
+#if !defined(MACOSX) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 #ifdef HL_WINDOWS_APP
