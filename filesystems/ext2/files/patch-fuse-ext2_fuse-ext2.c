--- fuse-ext2/fuse-ext2.c.orig	2019-05-09 08:29:33 UTC
+++ fuse-ext2/fuse-ext2.c
@@ -18,15 +18,14 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
  */
 
+#include <stdbool.h>
 #include "fuse-ext2.h"
 
 static const char *HOME = "http://github.com/alperakcan/fuse-ext2/";
 
 #if __FreeBSD__ == 10
-static char def_opts[] = "allow_other,default_permissions,local,";
 static char def_opts_rd[] = "noappledouble,";
 #else
-static char def_opts[] = "allow_other,default_permissions,";
 static char def_opts_rd[] = "";
 #endif
 
@@ -171,8 +170,10 @@ static int parse_options (int argc, char *argv[], stru
 static char * parse_mount_options (const char *orig_opts, struct extfs_data *opts)
 {
 	char *options, *s, *opt, *val, *ret;
+	bool allow_other = true;
+	bool default_permissions = true;
 
-	ret = malloc(strlen(def_opts) + strlen(def_opts_rd) + strlen(orig_opts) + 256 + PATH_MAX);
+	ret = malloc(strlen(def_opts_rd) + strlen(orig_opts) + 256 + PATH_MAX);
 	if (!ret) {
 		return NULL;
 	}
@@ -231,6 +232,14 @@ static char * parse_mount_options (const char *orig_op
 #if __FreeBSD__ == 10
 			strcat(ret, "force,");
 #endif
+		} else if (!strcmp(opt, "noallow_other")) {
+			allow_other = false;
+			strcat(ret, opt);
+			strcat(ret, ",");
+		} else if (!strcmp(opt, "nodefault_permissions")) {
+			default_permissions = false;
+			strcat(ret, opt);
+			strcat(ret, ",");
 		} else { /* Probably FUSE option. */
 			strcat(ret, opt);
 			if (val) {
@@ -246,7 +255,13 @@ static char * parse_mount_options (const char *orig_op
 		opts->readonly = 1;
 	}
 
-	strcat(ret, def_opts);
+	if (allow_other)
+		strcat(ret, "allow_other,");
+	if (default_permissions)
+		strcat(ret, "default_permissions,");
+#if __FreeBSD__ == 10
+	strcat(ret, "local,");
+#endif
 	if (opts->readonly == 1) {
 		strcat(ret, def_opts_rd);
 		strcat(ret, "ro,");
