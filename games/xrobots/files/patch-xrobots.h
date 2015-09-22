--- xrobots.h.orig	1989-11-17 22:37:40 UTC
+++ xrobots.h
@@ -33,21 +33,27 @@
  *
  */
 
+typedef struct {
+  Pixel		fg,
+  		bg;
+  Boolean	spiffy,		/* limited graphics 			*/
+		autoteleport,	/* teleport when sonic used, and no moves */
+		autoteleportalways,	/* teleport when no available moves */
+		showjumps,	/* show no intermediate moves 		*/
+		diewaiting;	/* die if you use wait unsafely 	*/
+  XtTranslations translations;
+  char		*score_filename;
+} AppData;
+
 /* 
  * from main.c
  */
+extern AppData	app_data;
 extern Display 	*display;
 extern Window 	playfield;
 extern Widget 	playfield_widget;
 extern GC 	gc,
 		cleargc;
-extern Pixel 	fg, 
-		bg;
-extern Boolean 	spiffy,
-		autoteleport,
-		autoteleportalways,
-		showjumps,
-		diewaiting;
 extern unsigned int
 		chasetime;
 
@@ -106,8 +112,6 @@ extern void 	check_score(), 
 
 extern void	show_scores_callback();
 
-extern char *score_filename;
-
 /*
  * from game.c
  */
@@ -146,9 +150,6 @@ extern int 	score,
 		game_active,
 		sonic_used;
 
-#define MIN(a,b) ((a<b)?a:b)
-#define MAX(a,b) ((a>b)?a:b)
-
 #define INXRANGE( _x_ )  (((_x_) >=0) && ((_x_)<MAXX))
 #define INYRANGE( _y_ )  (((_y_) >=0) && ((_y_)<MAXY))
 
