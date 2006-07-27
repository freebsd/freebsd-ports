diff -urN src.orig/proc.c src/proc.c
--- src.orig/proc.c    Tue Jul 25 21:29:20 2006
+++ src/proc.c Tue Jul 25 21:30:08 2006
@@ -352,7 +352,13 @@
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
