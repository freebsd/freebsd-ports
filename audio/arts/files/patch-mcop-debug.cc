--- mcop/debug.cc.orig	Sun Jul 13 21:33:40 2003
+++ mcop/debug.cc	Wed Aug 20 03:06:26 2003
@@ -785,6 +785,10 @@
 arts_strdup_vprintf (const char *format, va_list args1)
 {
   gchar *buffer;
+#ifdef HAVE_VASPRINTF
+  if (vasprintf (&buffer, format, args1) < 0)
+    buffer = NULL;
+#else
   va_list args2;
 
   G_VA_COPY (args2, args1);
@@ -793,7 +797,7 @@
 
   vsprintf (buffer, format, args2);
   va_end (args2);
-
+#endif
   return buffer;
 }
 
