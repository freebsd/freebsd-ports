--- src/cddb.h.orig	2004-06-15 22:13:19.000000000 +0200
+++ src/cddb.h	2008-06-26 20:13:57.000000000 +0200
@@ -30,7 +30,7 @@
 
 #include "tcd.h"
 
-extern int tcd_readdiskinfo(struct cd_info *cd, SDL_CD *cdrom);
+extern int tcd_readdiskinfo(struct tcd_state *cd, SDL_CD *cdrom);
 extern void tcd_writediskinfo(struct cd_info *cd, SDL_CD *cdrom);
 
 #endif /* TCD_CDDB_H */
