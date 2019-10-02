--- src/proc.c.orig	2008-08-24 00:37:18 UTC
+++ src/proc.c
@@ -352,7 +352,13 @@ bool sim_read_object_file (sim_t *sim, c
   // Microsoft freopen() isn't compliant with the C standard, which allows
   // NULL for the filename if you're reopening an existing file handle.
 #else
+  // XXX: for some reason this does not work.
+#if 0
   f = freopen (NULL, "r", f);
+#else
+  fclose(f);
+  f = fopen(fn, "rb");
+#endif
 #endif
   if (! f)
     {
