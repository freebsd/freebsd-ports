Use different temporary files for the displayed images.

--- source/os_glk.c.orig
+++ source/os_glk.c
@@ -1102,6 +1102,8 @@
       && gsclinux_graphics_enabled && glk_gestalt (gestalt_Graphics, 0))
     {
       sc_char *buffer;
+      char fname[80];
+      int fd;
 
       /*
        * Try to extract data with dd.  Assuming that works, background xv to
@@ -1110,15 +1112,23 @@
        * xv can usually use a small script, named xv, to invoke eog or an
        * alternative image display binary.  Not exactly finessed.
        */
+      strcpy(fname, "/tmp/scare-XXXXXX.jpg");
+      fd = mkstemps(fname, 4);
+      if (fd < 0)
+        return;
+      close(fd);
       assert (gsclinux_game_file);
       buffer = gsc_malloc (strlen (gsclinux_game_file) + 128);
-      sprintf (buffer, "dd if=%s ibs=1c skip=%ld count=%ld obs=100k"
-               " of=/tmp/scare.jpg 2>/dev/null",
-               gsclinux_game_file, offset, length);
+      sprintf (buffer, "dd if=%s ibs=1 skip=%ld count=%ld obs=100k"
+          " of=%s 2>/dev/null",
+          gsclinux_game_file, offset, length,
+          fname);
+      system (buffer);
+      sprintf (buffer, "xv %s >/dev/null 2>&1 &", fname);
+      system (buffer);
+      sprintf (buffer, "( sleep 10; rm %s ) >/dev/null 2>&1 &", fname);
       system (buffer);
       free (buffer);
-      system ("xv /tmp/scare.jpg >/dev/null 2>&1 &");
-      system ("( sleep 10; rm /tmp/scare.jpg ) >/dev/null 2>&1 &");
     }
 }
 #else
