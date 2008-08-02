--- src/app/main.c.orig	2008-06-02 08:16:24.000000000 +0400
+++ src/app/main.c	2008-08-02 19:32:26.000000000 +0400
@@ -19,6 +19,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <sys/param.h>
 #include "./main.h"
 #include "./globals.h"
 #include "./app.h"
@@ -56,6 +57,12 @@
 	if (command) free(command);
 }
 
+char *get_current_dir_name() {
+	char *buf = malloc(MAXPATHLEN);
+	getwd(buf);
+	return buf;
+}
+
 gchar *find_config_file() {
 //	Returns the config file name (name OPTION_FILE, defined in globals.h),
 //	with its full path
@@ -71,55 +78,22 @@
 //	if $HOME/DEF_DIR_NAME doesn't exist, we create the required files
 //	The directory where OPTION_FILE is found becomes the default one (DEF_DIR)
 
-	// Try ./OPTION_FILE
-	default_dir = (gchar *) get_current_dir_name();
-	path_n_file = concat_dname_fname(default_dir,OPTION_FILE);
-	if (!filexists(path_n_file)) { // Try ./DEF_DIR_NAME/OPTION_FILE
-		default_dir = concat_dname_fname(default_dir,DEF_DIR_NAME);
-		if (path_n_file)
-			free(path_n_file);
-		path_n_file = concat_dname_fname(default_dir,OPTION_FILE);
-		if (!filexists(path_n_file)) { // Try in the home directory - ~/OPTION_FILE
-			default_dir = getenv("HOME");
-			if (path_n_file)
-				free(path_n_file);
-			path_n_file = concat_dname_fname(default_dir, OPTION_FILE);
-			if (!filexists(path_n_file)) { // Try ~/DEFAULT_DIR/OPTION_FILE
-				default_dir = concat_dname_fname(default_dir,DEF_DIR_NAME);
-				if (path_n_file) free(path_n_file);
-				path_n_file = concat_dname_fname(default_dir, OPTION_FILE);
-				if (directory_exists(default_dir)) {
-					if (!filexists(path_n_file)) {
-						// Big problem, create a default rc file
-						create_config_file(path_n_file);
-					}
-				}
-				else {
-					// Geomorph directory ("default_dir") doesn't exist
-					// Create one with default scenes and rc file
-					buf = malloc(strlen(_("Creation of the default working directory?"))+1+strlen(default_dir));
-					sprintf(buf,_("Creation of the default working directory?"),default_dir);
-					if (!yes_no(buf,TRUE))
-						exit(0);
-					if (buf) free(buf);
-					shortcuts = yes_no(_("Add shortcuts on the KDE and GNOME desktops?"), TRUE);
-					command = concat_dname_fname(get_data_dir(),"install-step1-dir");
-					if (system(command))
-						my_msg(_("Fatal error during the creation of the default working directory"),ABORT);
-					if (command) free(command);
-					create_config_file(path_n_file);
-					if (shortcuts) {
-						command = concat_dname_fname(get_data_dir(),"install-step3-desktop");
-						if (system(command))
-							my_msg(_("Error during the creation of one shortcut or both"),WARNING);
-						if (buf) free(buf);
-						if (command) free(command);
-					}
-				if (path_n_file) free(path_n_file);
-				}
-			}
+	default_dir = concat_dname_fname(getenv("HOME"), DEF_DIR_NAME);
+	path_n_file = concat_dname_fname(default_dir, OPTION_FILE);
+	if (directory_exists(default_dir)) {
+		if (!filexists(path_n_file)) {
+			// Big problem, create a default rc file
+			create_config_file(path_n_file);
 		}
 	}
+	else {
+		command = concat_dname_fname(get_data_dir(),"install-step1-dir");
+		if (system(command))
+			my_msg(_("Fatal error during the creation of the default working directory"),ABORT);
+		if (command) free(command);
+		create_config_file(path_n_file);
+	}
+	if (path_n_file) free(path_n_file);
 	return add_filesep(default_dir);
 }
 
