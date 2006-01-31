--- src/filetypes.c.orig	Sat Jan 14 22:39:51 2006
+++ src/filetypes.c	Sun Jan 29 12:48:53 2006
@@ -104,15 +104,6 @@
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
 static struct file_type *register_file_type
 (gchar *name, gchar *ext, gboolean lossy,
  gboolean (*typecheck)(gchar *filename), 
@@ -971,7 +962,7 @@
      b = pipe_dialog_send_chunk(y,c,FALSE,dither_mode,bar);
      g_free(c);     
      if (x != NULL) gtk_object_sink(GTK_OBJECT(x));
-     if (!xunsetenv("OUTFILE")) g_free(d);
+     if (!xputenv("OUTFILE")) g_free(d);
      if (b || !file_exists(filename)) {
 	  *fatal = TRUE;
 	  return TRUE;
@@ -1240,7 +1231,7 @@
 	       gtk_object_sink(GTK_OBJECT(x));
 	  }
      }
-     if (!xunsetenv("OUTFILE")) g_free(c);
+     if (!xputenv("OUTFILE")) g_free(c);
      if (b || !file_exists(filename)) {
 	  *fatal = TRUE;
 	  return TRUE;
@@ -1254,7 +1245,11 @@
 static Chunk *try_mplayer(gchar *filename, int dither_mode, StatusBar *bar)
 {
      gchar *c,*d;
-     char *tempname;
+     gchar *tempname;
+     gchar *argv[] = { "sh", "-c", 
+		      "mplayer -quiet -noconsolecontrols "
+		      "-ao \"pcm:file=$OUTFILE\" -vc dummy -vo null "
+		      "\"$INFILE\"", NULL };
      Chunk *x;
      if (!program_exists("mplayer")) return NULL;
      tempname = get_temp_filename(0);
@@ -1263,20 +1258,16 @@
      if (xputenv(c)) { g_free(d); g_free(c); g_free(tempname); return NULL; }
      if (xputenv(d)) { 
 	  g_free(d); 
-	  if (!xunsetenv("OUTFILE"))
+	  if (!xputenv("OUTFILE"))
 	       g_free(c);
 	  g_free(tempname);
 	  return NULL; 
      }
-     char *argv[] = { "sh", "-c", 
-		      "mplayer -quiet -noconsolecontrols "
-		      "-ao \"pcm:file=$OUTFILE\" -vc dummy -vo null "
-		      "\"$INFILE\"", NULL };
 
      x = run_decoder(filename,tempname,"sh",argv,dither_mode,bar);
 
-     if (!xunsetenv("OUTFILE")) g_free(c);
-     if (!xunsetenv("INFILE")) g_free(d);
+     if (!xputenv("OUTFILE")) g_free(c);
+     if (!xputenv("INFILE")) g_free(d);
      g_free(tempname);
      
      return x;
