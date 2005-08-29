--- src/filetypes.c.orig	Sat Aug 13 02:01:54 2005
+++ src/filetypes.c	Sat Aug 13 15:45:17 2005
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
@@ -927,7 +918,7 @@
      b = pipe_dialog_send_chunk(y,c,FALSE,dither_mode,bar);
      g_free(c);     
      if (x != NULL) gtk_object_sink(GTK_OBJECT(x));
-     if (!xunsetenv("OUTFILE")) g_free(d);
+     if (!xputenv("OUTFILE")) g_free(d);
      if (b || !file_exists(filename)) {
 	  *fatal = TRUE;
 	  return TRUE;
@@ -985,7 +976,7 @@
 	       gtk_object_sink(GTK_OBJECT(x));
 	  }
      }
-     if (!xunsetenv("OUTFILE")) g_free(c);
+     if (!xputenv("OUTFILE")) g_free(c);
      if (b || !file_exists(filename)) {
 	  *fatal = TRUE;
 	  return TRUE;
@@ -999,7 +990,11 @@
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
@@ -1008,20 +1003,16 @@
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
