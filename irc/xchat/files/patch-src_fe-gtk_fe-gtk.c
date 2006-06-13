--- src/fe-gtk/fe-gtk.c	2006/06/07 06:16:51	1.66
+++ src/fe-gtk/fe-gtk.c	2006/06/12 03:23:23	1.67
@@ -225,7 +225,11 @@
 const char cursor_color_rc[] =
 	"style \"xc-ib-st\""
 	"{"
+#ifdef USE_GTKSPELL
+		"GtkTextView::cursor-color=\"#%02x%02x%02x\""
+#else
 		"GtkEntry::cursor-color=\"#%02x%02x%02x\""
+#endif
 	"}"
 	"widget \"*.xchat-inputbox\" style : application \"xc-ib-st\"";
 
