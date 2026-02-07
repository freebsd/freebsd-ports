--- src/cddb.c.orig	2004-06-15 21:20:09 UTC
+++ src/cddb.c
@@ -229,10 +229,11 @@ static char *cddb_filename(unsigned long
     return concat_strings(get_home_dir(), "/.tcd/", cd_id, NULL);
 }
 
-extern int tcd_readdiskinfo(struct cd_info *cd, SDL_CD * cdrom)
+extern int tcd_readdiskinfo(struct tcd_state *cds, SDL_CD * cdrom)
 {
     int result;
     char *filename;
+    struct cd_info *cd = &cds->cd_info;
 
     result = 0;
     if ((filename = cddb_filename(cddb_discid(cdrom))) != NULL) {
