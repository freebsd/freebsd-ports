$FreeBSD$

--- rogue/inventory.c	30 Nov 1999 03:49:23 -0000	1.4
+++ rogue/inventory.c	21 Aug 2003 19:58:45 -0000
@@ -415,14 +415,14 @@
 mix_colors()
 {
 	short i, j, k;
-	char *t;
+	char t[MAX_ID_TITLE_LEN];
 
 	for (i = 0; i <= 32; i++) {
 		j = get_rand(0, (POTIONS - 1));
 		k = get_rand(0, (POTIONS - 1));
-		t = id_potions[j].title;
-		id_potions[j].title = id_potions[k].title;
-		id_potions[k].title = t;
+		memcpy(t, id_potions[j].title, MAX_ID_TITLE_LEN);
+		memcpy(id_potions[j].title, id_potions[k].title, MAX_ID_TITLE_LEN);
+		memcpy(id_potions[k].title, t, MAX_ID_TITLE_LEN);
 	}
 }
 
