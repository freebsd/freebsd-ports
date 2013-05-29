--- a/ui/gtk.c
+++ b/ui/gtk.c
@@ -714,7 +718,11 @@ static gboolean gd_key_event(GtkWidget *
     } else if (gdk_keycode < 97) {
         qemu_keycode = gdk_keycode - 8;
     } else if (gdk_keycode < 158) {
+#if 0
         qemu_keycode = translate_evdev_keycode(gdk_keycode - 97);
+#else
+        qemu_keycode = translate_xfree86_keycode(gdk_keycode - 97);
+#endif
     } else if (gdk_keycode == 208) { /* Hiragana_Katakana */
         qemu_keycode = 0x70;
     } else if (gdk_keycode == 211) { /* backslash */
