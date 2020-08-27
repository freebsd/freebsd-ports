--- src/main.h.orig	2020-08-27 15:38:59 UTC
+++ src/main.h
@@ -51,7 +51,7 @@ typedef enum {
 
 extern PlayerID who_starts;
 
-gboolean player_active;
+extern gboolean player_active;
 
 void game_reset (void);
 void process_move (int move);
