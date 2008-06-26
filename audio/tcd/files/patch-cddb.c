--- src/cddb.c.orig	2004-06-15 23:20:09.000000000 +0200
+++ src/cddb.c	2008-06-26 20:15:03.000000000 +0200
@@ -39,6 +39,9 @@
 
 #include "cd-utils.h"
 #include "cddb.h"
+#ifdef USE_MUSICBRAINZ
+# include "tcd_mb.h"
+#endif
 #include "concat-strings.h"
 
 static void append_data(char *dest, const char *data, size_t maxlen)
@@ -229,12 +232,19 @@
     return concat_strings(get_home_dir(), "/.tcd/", cd_id, NULL);
 }
 
-extern int tcd_readdiskinfo(struct cd_info *cd, SDL_CD * cdrom)
+extern int tcd_readdiskinfo(struct tcd_state *cds, SDL_CD * cdrom)
 {
     int result;
     char *filename;
+    struct cd_info *cd = &cds->cd_info;
 
     result = 0;
+
+#ifdef USE_MUSICBRAINZ
+    if (!tcd_readmb(cds, cdrom))
+	return result;
+#endif
+
     if ((filename = cddb_filename(cddb_discid(cdrom))) != NULL) {
         result = tcd_readcddb(cd, cdrom, filename);
         free(filename);
