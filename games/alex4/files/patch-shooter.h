--- shooter.h.orig	2016-06-14 16:25:53 UTC
+++ shooter.h
@@ -83,8 +83,8 @@ typedef struct {
 	int difficulty;
 
 	// player related
-	long unsigned int score;
-	long unsigned int show_score;
+	unsigned int score;
+	unsigned int show_score;
 	int lives;
 	int power_gauge;
 	int power_level;
@@ -118,4 +118,4 @@ typedef struct {
 int start_shooter(Tcontrol *c, int with_sound);
 
 
-#endif
\ No newline at end of file
+#endif
