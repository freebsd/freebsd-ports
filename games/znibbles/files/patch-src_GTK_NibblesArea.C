--- src/GTK/NibblesArea.C.orig	1999-05-12 01:48:25 UTC
+++ src/GTK/NibblesArea.C
@@ -323,7 +323,7 @@ gint NibblesArea::draw_exp_cb(GtkWidget 
 			      GdkEventExpose *event, 
 			      NibblesArea *mythis)
 {
-  cout << "expose !" << endl;
+  std::cout << "expose !" << std::endl;
 
   if (!mythis->joined) {
     mythis->gif.join_game();
