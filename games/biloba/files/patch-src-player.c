--- src/player.c.orig	Fri Sep 23 19:09:02 2005
+++ src/player.c	Mon Oct  3 03:53:01 2005
@@ -259,6 +259,7 @@
 {
 	int i;
 	char *msg;
+	char num[2] = {((int)player->color)+1+'0', 0};
 	for (i = 0; i < game_num_players(); i++) {
 		LList *pawns = pawn_get_all((PawnColor)i);
 		for (; pawns; pawns = pawns->next) {
@@ -268,7 +269,6 @@
 		}
 		pawn_show_eaten();
 	}
-	char num[2] = {((int)player->color)+1+'0', 0};
 	if (player->name == NULL) {
 		msg = malloc(strlen(get_msg(M_PLAYER_LEAVES))+1);
 		strcpy(msg, get_msg(M_PLAYER));
