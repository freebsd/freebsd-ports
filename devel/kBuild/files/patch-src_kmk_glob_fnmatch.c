--- src/kmk/glob/fnmatch.c.orig	2026-01-31 20:06:09 UTC
+++ src/kmk/glob/fnmatch.c
@@ -120,7 +120,7 @@ USA.  */
 /* Avoid depending on library functions or files
    whose names are inconsistent.  */
 
-# if !defined _LIBC && !defined getenv && !defined _MSC_VER
+# if !defined _LIBC && !defined getenv && !defined _MSC_VER && !defined __FreeBSD__
 extern char *getenv ();
 # endif
 
