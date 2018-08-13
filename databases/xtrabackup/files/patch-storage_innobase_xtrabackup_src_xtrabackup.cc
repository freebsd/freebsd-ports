--- storage/innobase/xtrabackup/src/xtrabackup.cc.orig	2018-08-09 13:53:57 UTC
+++ storage/innobase/xtrabackup/src/xtrabackup.cc
@@ -8236,10 +8236,6 @@ xb_init()
 
 	if (xtrabackup_backup) {
 
-		if (!opt_noversioncheck) {
-			version_check();
-		}
-
 		if ((mysql_connection = xb_mysql_connect()) == NULL) {
 			return(false);
 		}
