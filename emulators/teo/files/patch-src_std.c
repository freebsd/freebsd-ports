--- src/std.c.orig	2017-11-03 16:40:23 UTC
+++ src/std.c
@@ -364,8 +364,7 @@ char *std_ApplicationPath (const char di
 {
     static char *fname = NULL;
 
-    fname = NULL;
-#ifdef DEBIAN_BUILD
+#if !defined(__DJGPP__) && !defined(_WIN32)
     /* create private directory if necessary */
     fname = std_strdup_printf ("%s/.config/%s", getenv("HOME"), dirname);
     if (access (fname, F_OK) < 0)
