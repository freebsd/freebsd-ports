--- rogue/inventory.c.orig	2016-05-12 14:49:52 UTC
+++ rogue/inventory.c
@@ -417,6 +417,7 @@ mix_colors(void)
 		k = get_rand(0, (POTIONS - 1));
 		memcpy(t, id_potions[j].title, MAX_ID_TITLE_LEN);
 		memcpy(id_potions[j].title, id_potions[k].title, MAX_ID_TITLE_LEN);
+		memcpy(id_potions[k].title, t, MAX_ID_TITLE_LEN);
 	}
 }
 
