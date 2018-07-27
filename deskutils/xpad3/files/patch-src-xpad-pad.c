--- src/xpad-pad.c.orig	2009-01-11 16:27:39 UTC
+++ src/xpad-pad.c
@@ -274,7 +274,7 @@ xpad_pad_init (XpadPad *pad)
 		"gravity", GDK_GRAVITY_STATIC, /* static gravity makes saving pad x,y work */
 		"skip-pager-hint", !xpad_settings_get_has_decorations (xpad_settings ()),
 		"skip-taskbar-hint", !xpad_settings_get_has_decorations (xpad_settings ()),
-		"type", GTK_WINDOW_TOPLEVEL,
+		/*"type", GTK_WINDOW_TOPLEVEL,*/
 		"type-hint", GDK_WINDOW_TYPE_HINT_NORMAL,
 		"window-position", GTK_WIN_POS_MOUSE,
 		"child", vbox,
