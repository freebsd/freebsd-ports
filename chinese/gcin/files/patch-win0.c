--- win0.c.orig	Tue Oct  4 22:35:52 2005
+++ win0.c	Tue Oct  4 13:25:26 2005
@@ -28,6 +28,8 @@
 static GtkWidget *button_eng_ph;
 static int max_yl;
 
+static void create_win0_gui();
+
 static void recreate_win0()
 {
   int i;
@@ -41,8 +43,8 @@
 
 void change_win0_style()
 {
-  if (!top_bin || current_pho_simple_win == pho_simple_win &&
-      current_gcin_inner_frame == gcin_inner_frame)
+  if (!top_bin || (current_pho_simple_win == pho_simple_win &&
+      current_gcin_inner_frame == gcin_inner_frame))
     return;
 
   gtk_widget_destroy(top_bin);
@@ -153,7 +155,7 @@
 }
 
 
-void disp_char(int index, u_char *ch)
+void disp_char(int index, char *ch)
 {
   char tt[CH_SZ+1];
 
@@ -342,6 +344,7 @@
   raw_move(best_win_x, best_win_y);
 }
 
+gboolean tsin_has_input();
 
 void move_win0(int x, int y)
 {
@@ -505,9 +508,9 @@
   pango_attr_list_insert (attr_list, white_fg);
 }
 
+void create_win1_gui();
 
-
-void create_win0_gui()
+static void create_win0_gui()
 {
   if (top_bin)
     return;
