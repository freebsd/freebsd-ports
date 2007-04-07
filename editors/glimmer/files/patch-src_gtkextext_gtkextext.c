--- src/gtkextext/gtkextext.c.orig	Sat Apr  7 01:47:56 2007
+++ src/gtkextext/gtkextext.c	Sat Apr  7 01:52:20 2007
@@ -1140,7 +1140,8 @@ line_set_cursor_pos (GtkExText * text, g
         val = (gfloat) width;
         gtk_adjustment_set_value (text->hadj, val);
     } else if (text->draw_numbers && width < (val + text->gutter_width)) {
-        val = (gfloat) width -= text->gutter_width;
+        width -= text->gutter_width;
+        val = (gfloat) width;
         gtk_adjustment_set_value (text->hadj, val);
     }
 
