--- src/app/main.c.orig	Sun Nov  6 08:52:50 2005
+++ src/app/main.c	Tue Feb 28 04:00:28 2006
@@ -19,6 +19,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <sys/param.h>
 #include "./main.h"
 #include "./globals.h"
 // Gtkglext - 2005-11
@@ -48,37 +49,21 @@
 	if (command) free(command);
 }
 
+char *get_current_dir_name() {
+	char *buf = malloc(MAXPATHLEN);
+	getwd(buf);
+	return buf;
+}
+
 gchar *find_config_file() {
 //	Returns the config file name (name OPTIONS_FILE, defined in globals.h),
 //	with its full path
 	gchar *default_dir, *path_n_file, *buf, *command;
 	gboolean shortcuts;
 
-//	We try:
-//	1. in the current directory. (./OPTIONS_FILE = ./geomorphrc)
-//	2. if not found, we try ./DEFAULT_DIR/OPTIONS_FILE (./geomorph/geomorphrc)
-//	3. if not found, we try $HOME/OPTIONS_FILE (~/geomorphrc)
-//	4. if not found, we try in $HOME/DEFAULT_DIR (~/geomorph/geomorphrc) 
-//	--> if OPTIONS_FILE was not found, and 
-//	if $HOME/DEFAULT_DIR doesn't exist, we create the required files
-//	The directory where OPTIONS_FILE is found becomes the default one (DEF_DIR)
-
-	// Try ./OPTIONS_FILE
-	default_dir = (gchar *) get_current_dir_name();
-	path_n_file = concat_dname_fname(default_dir,OPTIONS_FILE);
-	if (!filexists(path_n_file)) { // Try ./DEFAULT_DIR/OPTIONS_FILE
-		default_dir = concat_dname_fname(default_dir,DEFAULT_DIR);
-		if (path_n_file)
-			free(path_n_file);
-		path_n_file = concat_dname_fname(default_dir,OPTIONS_FILE);
-		if (!filexists(path_n_file)) { // Try in the home directory - ~/OPTIONS_FILE
+	// Config file is located under $HOME/.geomorph/geomorphrc
 			default_dir = getenv("HOME");
-			if (path_n_file)
-				free(path_n_file);
-			path_n_file = concat_dname_fname(default_dir, OPTIONS_FILE);
-			if (!filexists(path_n_file)) { // Try ~/DEFAULT_DIR/OPTIONS_FILE
 				default_dir = concat_dname_fname(default_dir,DEFAULT_DIR);
-				if (path_n_file) free(path_n_file);
 				path_n_file = concat_dname_fname(default_dir, OPTIONS_FILE);
 				if (directory_exists(default_dir)) {
 					if (!filexists(path_n_file)) {
@@ -109,9 +94,6 @@
 					}
 				if (path_n_file) free(path_n_file);
 				}
-			}
-		}
-	}
 	return add_filesep(default_dir);
 }
 
