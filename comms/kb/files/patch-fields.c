--- fields.c.orig	2007-09-10 10:57:01.000000000 -0400
+++ fields.c	2007-11-22 19:53:19.000000000 -0500
@@ -1418,6 +1418,12 @@
   gint cyan_bar_color, text_color;
   gchar str_hold[81];
 
+  /* If esk->ikey is nul shunt it off here. I saw it happen - db VA3DB */
+  if (esd->ikey == '\0')
+    {
+      play_bells (BELL_SOUND);
+      return;
+    }
   beep = 1;
   ccol = *esd->cursor_colp-esd->field_col;
   lflp = strlen(esd->field_linep);
