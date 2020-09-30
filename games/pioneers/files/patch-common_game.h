--- common/game.h.orig	2018-03-14 13:44:46 UTC
+++ common/game.h
@@ -137,7 +137,7 @@ typedef enum {
 typedef void (*WriteLineFunc) (gpointer user_data, const gchar *);
 
 /** Default style for a player. */
-const gchar *default_player_style;
+extern const gchar *default_player_style;
 
 GameParams *params_new(void);
 GameParams *params_copy(const GameParams * params);
