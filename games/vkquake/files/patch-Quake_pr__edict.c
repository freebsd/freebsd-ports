 vkQuake is packaged with .orig files in ${WRKSRC}/Misc/vq_pak/maps, these
 files will conflict with the makepatch script in
 ${PORTSDIR}/Mk/Scripts/smart_makepatch.sh, which results in a makepatch
 process that does not generate this patch. To get around this, remove
 ${WRKSRC}/Misc/vq_pak/maps when the patches need to be regenerated.

--- Quake/pr_edict.c.orig	2025-05-01 11:30:09 UTC
+++ Quake/pr_edict.c
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
