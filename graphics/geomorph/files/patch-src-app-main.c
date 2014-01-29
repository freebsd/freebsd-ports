--- src/app/main.c.orig	2010-10-30 08:17:00.000000000 +0400
+++ src/app/main.c	2013-08-28 03:51:05.535226256 +0400
@@ -18,6 +18,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <sys/param.h>
 #include "./main.h"
 #include "./globals.h"
 #include "./app.h"
@@ -68,6 +69,12 @@
 	if (command) x_free(command);
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
@@ -83,59 +90,23 @@
 //	if $HOME/DEF_DIR_NAME doesn't exist, we create the required files
 //	The directory where OPTION_FILE is found becomes the default one (DEF_DIR)
 
-	// Try ./OPTION_FILE
-	default_dir = (gchar *) get_current_dir_name();
-	path_n_file = concat_dname_fname(default_dir,OPTION_FILE);
-	if (!filexists(path_n_file)) { // Try ./DEF_DIR_NAME/OPTION_FILE
-		default_dir = concat_dname_fname(default_dir,DEF_DIR_NAME);
-		if (path_n_file)
-			x_free(path_n_file);
-		path_n_file = concat_dname_fname(default_dir,OPTION_FILE);
-		if (!filexists(path_n_file)) { // Try in the home directory - ~/OPTION_FILE
-			default_dir = getenv("HOME");
-			if (path_n_file)
-				x_free(path_n_file);
-			path_n_file = concat_dname_fname(default_dir, OPTION_FILE);
-			if (!filexists(path_n_file)) { // Try ~/DEFAULT_DIR/OPTION_FILE
-				default_dir = concat_dname_fname(default_dir,DEF_DIR_NAME);
-				if (path_n_file) x_free(path_n_file);
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
-					buf = (gchar *) x_malloc(strlen(_("Creation of the default working directory?"))+1+strlen(default_dir), "const gchar (buf - Creation of the default working directory MSG)");
-					sprintf(buf,_("Creation of the default working directory?"),default_dir);
-					if (!yes_no(buf,TRUE))
-						exit(0);
-//					if (buf) x_free(buf);
-					shortcuts = yes_no(_("Add shortcuts on the KDE and GNOME desktops?"), TRUE);
-					command = concat_dname_fname(get_data_dir(),"install-step1-dir");
-					if (system(command))
-						my_msg(_("Fatal error during the creation of the default working directory"),ABORT);
-					if (command) x_free(command);
-					create_config_file(path_n_file);
-					command = concat_dname_fname(get_data_dir(),"install-step3-menu");
-					if (system(command))
-						my_msg(_("Error during the creation of Geomorph in the Gnome or KDE menu"),WARNING);
-					if (command) x_free(command);
-					if (shortcuts) {
-						command = concat_dname_fname(get_data_dir(),"install-step4-desktop");
-						if (system(command))
-							my_msg(_("Error during the creation of one shortcut or both"),WARNING);
-//						if (buf) x_free(buf);
-						if (command) x_free(command);
-					}
-				if (path_n_file) x_free(path_n_file);
-				}
-			}
+	default_dir = concat_dname_fname(getenv("HOME"), DEF_DIR_NAME);
+	path_n_file = path_n_file = concat_dname_fname(default_dir, OPTION_FILE);
+
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
 
