--- w_cmdpanel.c.orig	Tue Jul 26 09:46:46 2005
+++ w_cmdpanel.c
@@ -1614,12 +1614,12 @@
 static void
 paste_char(Widget w, XtPointer client_data, XtPointer call_data)
 {
-    unsigned char *chr = (unsigned char *) client_data;
+    unsigned char chr = (unsigned char) client_data;
 
     /* only allow during text input */
-    if (canvas_kbd_proc != char_handler)
+    if (canvas_kbd_proc != (void (*)())char_handler)
 	return;
-    char_handler((XKeyEvent *) 0, *chr, (KeySym) 0);
+    char_handler((XKeyEvent *) 0, chr, (KeySym) 0);
 }
 
 /* add or remove a checkmark to a menu entry to show that it
