--- src/nano.c.orig	2018-09-14 11:02:24 UTC
+++ src/nano.c
@@ -2580,7 +2580,7 @@ int main(int argc, char **argv)
 	controlhome = get_keycode("kHOM5", CONTROL_HOME);
 	controlend = get_keycode("kEND5", CONTROL_END);
 	controldelete = get_keycode("kDC5", CONTROL_DELETE);
-	controlshiftdelete = get_keycode("kDC6", KEY_BACKSPACE);
+	controlshiftdelete = get_keycode("kDC6", CONTROL_SHIFT_DELETE);
 #ifndef NANO_TINY
 	/* Ask for the codes for Shift+Control+Left/Right/Up/Down. */
 	shiftcontrolleft = get_keycode("kLFT6", SHIFT_CONTROL_LEFT);
