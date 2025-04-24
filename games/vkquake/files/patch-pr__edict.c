--- pr_edict.c.orig	2025-04-24 00:38:02 UTC
+++ pr_edict.c
@@ -883,8 +883,8 @@ void ED_PrintEdicts (void)
 */
 void ED_PrintEdicts (void)
 {
-	int free_edicts_count = 0;
-	int free_list_count = 0;
+	int free_edicts_count __attribute__((unused)) = 0;
+	int free_list_count __attribute__((unused)) = 0;
 
 	if (!sv.active)
 		return;
