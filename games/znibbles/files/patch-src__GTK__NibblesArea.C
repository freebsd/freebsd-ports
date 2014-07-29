--- src/GTK/NibblesArea.C	Wed May 12 11:48:25 1999
+++ src/GTK/NibblesArea.C	Sat Oct 26 00:37:26 2002
@@ -323,7 +323,7 @@
 			      GdkEventExpose *event, 
 			      NibblesArea *mythis)
 {
-  cout << "expose !" << endl;
+  std::cout << "expose !" << std::endl;
 
   if (!mythis->joined) {
     mythis->gif.join_game();
