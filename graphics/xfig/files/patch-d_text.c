--- d_text.c.orig	Tue Jul 26 09:39:58 2005
+++ d_text.c
@@ -112,7 +112,7 @@
 static void	move_text(int dir, unsigned char c, float div);
 static void	reload_compoundfont(F_compound *compounds);
 static int	prefix_length(char *string, int where_p);
-static void	initialize_char_handler(Window w, int (*cr) (/* ??? */), int bx, int by);
+static void	initialize_char_handler(Window w, void (*cr) (/* ??? */), int bx, int by);
 static void	terminate_char_handler(void);
 static void	turn_on_blinking_cursor(void (*draw_cursor) (/* ??? */), void (*erase_cursor) (/* ??? */), int x, int y, long unsigned int msec);
 static void	turn_off_blinking_cursor(void);
@@ -336,7 +336,7 @@
     set_mousefun("new text", "finish text", "cancel", "", "paste text", "");
     draw_mousefun_kbd();
     draw_mousefun_canvas();
-    canvas_kbd_proc = char_handler;
+    canvas_kbd_proc = (void (*)())char_handler;
     canvas_middlebut_proc = finish_text_input;
     canvas_leftbut_proc = finish_n_start;
     canvas_rightbut_proc = cancel_text_input;
@@ -463,7 +463,7 @@
     set_mousefun("new text", "finish text", "cancel", "", "paste text", "");
     draw_mousefun_kbd();
     draw_mousefun_canvas();
-    canvas_kbd_proc = char_handler;
+    canvas_kbd_proc = (void (*)())char_handler;
     canvas_middlebut_proc = finish_text_input;
     canvas_leftbut_proc = finish_n_start;
     canvas_rightbut_proc = cancel_text_input;
@@ -782,7 +782,7 @@
 static int	cbase_x, cbase_y;
 static float	rbase_x, rbase_y, rcur_x, rcur_y;
 
-static int	(*cr_proc) ();
+static void	(*cr_proc) ();
 
 static void
 draw_cursor(int x, int y)
@@ -794,7 +794,7 @@
 }
 
 static void
-initialize_char_handler(Window w, int (*cr) (/* ??? */), int bx, int by)
+initialize_char_handler(Window w, void (*cr) (/* ??? */), int bx, int by)
 {
     pw = w;
     cr_proc = cr;
