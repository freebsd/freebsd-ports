--- src/filetypes.c.orig	Tue Jul 25 05:06:59 2006
+++ src/filetypes.c	Tue Aug 22 15:52:56 2006
@@ -1258,7 +1258,11 @@
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
@@ -1272,10 +1276,6 @@
 	  g_free(tempname);
 	  return NULL; 
      }
-     char *argv[] = { "sh", "-c", 
-		      "mplayer -quiet -noconsolecontrols "
-		      "-ao \"pcm:file=$OUTFILE\" -vc dummy -vo null "
-		      "\"$INFILE\"", NULL };
 
      x = run_decoder(filename,tempname,"sh",argv,dither_mode,bar);
 
