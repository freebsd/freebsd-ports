--- storage/innobase/xtrabackup/src/backup_copy.cc.orig	2018-08-09 14:07:34 UTC
+++ storage/innobase/xtrabackup/src/backup_copy.cc
@@ -53,7 +53,6 @@ Place, Suite 330, Boston, MA 02111-1307 USA
 #include <string>
 #include <mysqld.h>
 #include <my_default.h>
-#include <version_check_pl.h>
 #include <sstream>
 #include <algorithm>
 #include "fil_cur.h"
@@ -2296,35 +2295,4 @@ decrypt_decompress()
 	sync_check_close();
 
 	return(ret);
-}
-
-void
-version_check()
-{
-	if (opt_password != NULL) {
-		setenv("option_mysql_password", opt_password, 1);
-	}
-	if (opt_user != NULL) {
-		setenv("option_mysql_user", opt_user, 1);
-	}
-	if (opt_host != NULL) {
-		setenv("option_mysql_host", opt_host, 1);
-	}
-	if (opt_socket != NULL) {
-		setenv("option_mysql_socket", opt_socket, 1);
-	}
-	if (opt_port != 0) {
-		char port[20];
-		snprintf(port, sizeof(port), "%u", opt_port);
-		setenv("option_mysql_port", port, 1);
-	}
-
-	FILE *pipe = popen("perl", "w");
-	if (pipe == NULL) {
-		return;
-	}
-
-	fwrite((const char *) version_check_pl, version_check_pl_len, 1, pipe);
-
-	pclose(pipe);
 }
