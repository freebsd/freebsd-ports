--- os_glk.c.orig	Sat Feb  5 19:58:33 2005
+++ os_glk.c	Sat Feb  5 20:17:22 2005
@@ -899,6 +899,8 @@
 		&& glk_gestalt (gestalt_Graphics, 0))
 	    {
 		sc_char		*buffer;
+		char		 fname[80];
+		int		 fd;
 
 		/*
 		 * Try to extract data with dd.  Assuming that works, back-
@@ -906,15 +908,23 @@
 		 * delay ten seconds and then delete the temporary file
 		 * containing the image.  Not exactly finessed.
 		 */
+		strcpy(fname, "/tmp/scare-XXXXXX.jpg");
+		fd = mkstemps(fname, 4);
+		if (fd < 0)
+			return;
+		close(fd);
 		assert (gsclinux_game_file != NULL);
 		buffer = gsc_malloc (strlen (gsclinux_game_file) + 128);
-		sprintf (buffer, "dd if=%s ibs=1c skip=%ld count=%ld obs=100k"
-				 " of=/tmp/scare.jpg 2>/dev/null",
-					gsclinux_game_file, offset, length);
+		sprintf (buffer, "dd if=%s ibs=1 skip=%ld count=%ld obs=100k"
+				 " of=%s 2>/dev/null",
+					gsclinux_game_file, offset, length,
+					fname);
+		system (buffer);
+		sprintf (buffer, "xv %s >/dev/null 2>&1 &", fname);
+		system (buffer);
+		sprintf (buffer, "( sleep 10; rm %s ) >/dev/null 2>&1 &", fname);
 		system (buffer);
 		free (buffer);
-		system ("xv /tmp/scare.jpg >/dev/null 2>&1 &");
-		system ("( sleep 10; rm /tmp/scare.jpg ) >/dev/null 2>&1 &");
 	    }
 }
 #else
