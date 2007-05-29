--- movelog.c.orig	Tue May 29 18:49:36 2007
+++ movelog.c	Tue May 29 18:52:19 2007
@@ -33,6 +33,9 @@
 
 extern int	cheat_count;
 
+static int card_to_int(CardPtr card);
+static int restore_game(char *str, char *str2);
+
 make_deck_cache()
 {
 CardPtr	tmp;
