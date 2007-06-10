--- w_canvas.c.orig	Tue Jul 26 09:40:00 2005
+++ w_canvas.c
@@ -558,7 +558,7 @@
 			       }
 			       lbuf[len] = '\0';
 			       if (0 < len) {
-				 if (2 <= len && canvas_kbd_proc == char_handler) {
+				 if (2 <= len && canvas_kbd_proc == (void (*)())char_handler) {
 				   i18n_char_handler(lbuf);
 				 } else {
 				   for (i = 0; i < len; i++) {
@@ -663,7 +663,7 @@
 {
 	Time event_time;
 
-	if (canvas_kbd_proc != char_handler)
+	if (canvas_kbd_proc != (void (*)())char_handler)
 		return;
 
 	if (paste_event != NULL)
@@ -710,7 +710,7 @@
 	    if (ret_status == Success || 0 < num_values) {
 	      for (i = 0; i < num_values; i++) {
 		for (c = tmp[i]; *c; c++) {
-		  if (canvas_kbd_proc == char_handler && ' ' <= *c && *(c + 1)) {
+		  if (canvas_kbd_proc == (void (*)())char_handler && ' ' <= *c && *(c + 1)) {
 		    prefix_append_char(*c);
 		  } else {
 		    canvas_kbd_proc((XKeyEvent *) 0, *c, (KeySym) 0);
@@ -937,7 +937,7 @@
   active_mode_panel = None;
 }
 
-void static mode_panel_button_selected(Widget w, char *icon, char *call_data)
+void static mode_panel_button_selected(Widget w, icon_struct *icon, char *call_data)
 {
   change_mode(icon);
   popdown_mode_panel();
