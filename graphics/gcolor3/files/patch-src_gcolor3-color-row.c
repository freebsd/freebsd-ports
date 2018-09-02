https://github.com/Hjdskes/gcolor3/commit/9130ffeff091fbafff6a0c8f06b09f54657d5dfd

../src/gcolor3-color-row.c:88:6: error: implicit conversion from enumeration type 'GtkStateType' to different enumeration type 'GtkStateFlags' [-Werror,-Wenum-conversion]
                                        GTK_STATE_NORMAL,
                                        ^~~~~~~~~~~~~~~~

--- src/gcolor3-color-row.c.orig	2018-09-02 12:20:53 UTC
+++ src/gcolor3-color-row.c
@@ -85,7 +85,7 @@ set_color_thumbnail (Gcolor3ColorRow *row)
 	gtk_style_context_save (style_context);
 	gtk_style_context_get_property (style_context,
 					GTK_STYLE_PROPERTY_BORDER_RADIUS,
-					GTK_STATE_NORMAL,
+					GTK_STATE_FLAG_NORMAL,
 					&border_radius);
 	gtk_style_context_restore (style_context);
 
