--- xpipeman.h.orig	1991-09-13 20:32:14 UTC
+++ xpipeman.h
@@ -31,6 +31,13 @@
  * 
  */
 
+typedef struct {
+  Pixel fg;
+  Pixel bg;
+  XtTranslations translations;
+  char *score_filename;
+} AppData;
+
 /* 
  * from main.c
  */
@@ -39,8 +46,8 @@ extern Window 	playfield;
 extern Widget 	playfield_widget;
 extern GC 	gc,
 		cleargc;
-extern Pixel 	fg, 
-		bg;
+
+extern AppData app_data;
 
 extern void 	update_score();
 extern void 	update_level();
@@ -118,8 +125,6 @@ extern void 	check_score(), 
 
 extern void	show_scores_callback();
 
-extern char *score_filename;
-
 /*
  * from game.c
  */
@@ -188,4 +193,7 @@ extern void  show_level_over_popup(),
              show_game_over_popup(),
 	     level_over_popdown(),
 	     game_over_popdown(),
+	     show_nomore_popup(),
+	     nomore_popdown(),
+	     all_popdown(),
 	     create_general_popups();
