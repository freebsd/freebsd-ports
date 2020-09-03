--- movelog.c.orig	1991-09-28 17:46:17 UTC
+++ movelog.c
@@ -28,10 +28,13 @@ static int	move_index = 0;
 static int	*move_cache = NULL;
 static int	cache_size = 0;
 
-int	deck_cache[NUM_CARDS];
-int	deck_index = 0;
+int		deck_cache[NUM_CARDS];
+int		deck_index = 0;
 
 extern int	cheat_count;
+
+static int card_to_int(CardPtr card);
+static int restore_game(char *str, char *str2);
 
 make_deck_cache()
 {
