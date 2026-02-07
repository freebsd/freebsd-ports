--- tty.c.orig	2003-10-24 10:48:27 UTC
+++ tty.c
@@ -550,7 +550,7 @@ static void setup_fields(void)
     mvaddstr(y, x-1, buf);
     for (i = 2; i < FIELD_HEIGHT*2 && players[my_playernum-1][i-2]; i++)
 	mvaddch(y+i, x-1, players[my_playernum-1][i-2]);
-    if (teams[my_playernum-1] != '\0') {
+    if (teams[my_playernum-1] != NULL) {
 	mvaddstr(y, x+FIELD_WIDTH*2+2, "T");
 	for (i = 2; i < FIELD_HEIGHT*2 && teams[my_playernum-1][i-2]; i++)
 	    mvaddch(y+i, x+FIELD_WIDTH*2+2, teams[my_playernum-1][i-2]);
@@ -586,7 +586,7 @@ static void setup_fields(void)
 	    if (players[j+1]) {
 		for (i = 0; i < FIELD_HEIGHT-2 && players[j+1][i]; i++)
 		    mvaddch(y+i+2, x-1, players[j+1][i]);
-		if (teams[j+1] != '\0') {
+		if (teams[j+1] != NULL) {
 		    mvaddstr(y, x+FIELD_WIDTH+2, "T");
 		    for (i = 0; i < FIELD_HEIGHT-2 && teams[j+1][i]; i++)
 			mvaddch(y+i+2, x+FIELD_WIDTH+2, teams[j+1][i]);
@@ -599,7 +599,7 @@ static void setup_fields(void)
 	    if (players[j]) {
 		for (i = 0; i < FIELD_HEIGHT-2 && players[j][i]; i++)
 		    mvaddch(y+i+2, x-1, players[j][i]);
-		if (teams[j] != '\0') {
+		if (teams[j] != NULL) {
 		    mvaddstr(y, x+FIELD_WIDTH+2, "T");
 		    for (i = 0; i < FIELD_HEIGHT-2 && teams[j][i]; i++)
 			mvaddch(y+i+2, x+FIELD_WIDTH+2, teams[j][i]);
