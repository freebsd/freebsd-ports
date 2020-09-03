--- fuse/ui/widget/widget.c.orig	2020-02-07 11:00:48 UTC
+++ fuse/ui/widget/widget.c
@@ -93,7 +93,7 @@ typedef struct widget_recurse_t {
 static widget_recurse_t widget_return[10]; /* The stack to recurse on */
 
 /* The settings used whilst playing with an options dialog box */
-settings_info widget_options_settings;
+extern settings_info widget_options_settings;
 
 static int widget_read_font( const char *filename )
 {
