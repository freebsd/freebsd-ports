--- flow/gsl/gslglib.c.orig	Wed May  7 13:50:15 2003
+++ flow/gsl/gslglib.c	Wed Aug 20 03:06:26 2003
@@ -44,6 +44,10 @@
 		  va_list      args1)
 {
   gchar *buffer;
+#ifdef HAVE_VASPRINTF
+  if (vasprintf (&buffer, format, args1) < 0)
+    buffer = NULL;
+#else
   va_list args2;
 
   G_VA_COPY (args2, args1);
@@ -52,7 +56,7 @@
 
   vsprintf (buffer, format, args2);
   va_end (args2);
-
+#endif
   return buffer;
 }
 gchar *
