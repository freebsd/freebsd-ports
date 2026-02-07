--- src/server/variable.c.orig	2021-02-18 22:26:47 UTC
+++ src/server/variable.c
@@ -254,10 +254,11 @@ s16b target_row;*/
 /* Collection of connections/players */
 element_group* players = NULL;
 
-/* User info */
+/* User info in z-file.c 
 int player_uid = 0;
 int player_euid = 0;
 int player_egid = 0;
+*/
 
 /* The array of players */
 player_type **Players;
