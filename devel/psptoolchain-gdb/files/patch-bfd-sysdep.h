--- ./bfd/sysdep.h.orig	2009-09-02 07:18:37.000000000 +0000
+++ ./bfd/sysdep.h	2012-01-25 22:24:22.000000000 +0000
@@ -131,7 +131,7 @@
 extern PTR realloc ();
 #endif
 
-#if !HAVE_DECL_STPCPY
+#if !HAVE_DECL_STPCPY && !defined(stpcpy)
 extern char *stpcpy (char *__dest, const char *__src);
 #endif
 
