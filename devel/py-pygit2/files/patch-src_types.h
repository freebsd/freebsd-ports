--- src/types.h.orig	2021-09-09 11:47:02 UTC
+++ src/types.h
@@ -32,8 +32,8 @@
 #include <Python.h>
 #include <git2.h>
 
-#if !(LIBGIT2_VER_MAJOR == 1 && LIBGIT2_VER_MINOR == 1)
-#error You need a compatible libgit2 version (1.1.x)
+#if !(LIBGIT2_VER_MAJOR == 1 && LIBGIT2_VER_MINOR == 2)
+#error You need a compatible libgit2 version (1.2.x)
 #endif
 
 /*
