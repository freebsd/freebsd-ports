--- X-gfx1.c.orig
+++ X-gfx1.c
@@ -442,7 +442,7 @@
         /* build internal cardset */
 	CARD_WIDTH = -1;
 	if (xpm) {
-	    char s[200];
+	    char s[MAXXPMDIRLEN + 15];
 	    FILE *fp;
 	    sprintf(s, "%s/Cards.conf", xpmdir);
 	    if ((fp = fopen(s, "r"))) {
@@ -956,7 +956,8 @@
 		    cardpicts[57] = 0;	/* Joker is loaded on request */
 		    for (i = 0; i <= 56; ++i) {
 			if (xpmdir && (i < 52 || i >= 56)) {
-			    char s[200];
+			    char s[MAXXPMDIRLEN + strlen(US_rank_name[RANK(i)]) +
+                                   strlen(US_suit_name[SUIT(i)]) + 20];
 			    if (i == CARDBACK) {
 				strcpy(s, xpmdir);
 			        strcat(s, "/Cardback.xpm");
@@ -988,7 +989,7 @@
 		    if (!cardpicts[c]) {
 			/* must load or draw joker */
 			if (xpmdir) {
-			    char s[200];
+			    char s[MAXXPMDIRLEN + 15];
 			    sprintf(s, "%s/Joker.xpm", xpmdir);
 			    (void)read_pixmap(s, &cardpicts[c]);
 			}
