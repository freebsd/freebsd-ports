--- src/filetypes.c.orig	Wed Jul 13 07:44:46 2005
+++ src/filetypes.c	Thu Jul 14 01:59:03 2005
@@ -97,15 +97,6 @@
      return FALSE;
 }
 
-static gboolean xunsetenv(char *varname)
-{
-     if (unsetenv(varname) != 0) {
-	  console_message(_("unsetenv failed!"));
-	  return TRUE;
-     }
-     return FALSE;
-}
-
 static void register_file_type(gchar *name, gchar *ext, 
 			       gboolean (*typecheck)(gchar *filename),
 			       Chunk *(*load)(gchar *filename, 
@@ -922,7 +913,7 @@
      b = pipe_dialog_send_chunk(y,c,FALSE,dither_mode,bar);
      g_free(c);     
      if (x != NULL) gtk_object_sink(GTK_OBJECT(x));
-     if (!xunsetenv("OUTFILE")) g_free(d);
+     if (!xputenv("OUTFILE")) g_free(d);
      if (b || !file_exists(filename)) {
 	  *fatal = TRUE;
 	  return TRUE;
@@ -980,7 +971,7 @@
 	       gtk_object_sink(GTK_OBJECT(x));
 	  }
      }
-     if (!xunsetenv("OUTFILE")) g_free(c);
+     if (!xputenv("OUTFILE")) g_free(c);
      if (b || !file_exists(filename)) {
 	  *fatal = TRUE;
 	  return TRUE;
