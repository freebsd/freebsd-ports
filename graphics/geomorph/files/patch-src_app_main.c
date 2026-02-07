--- src/app/main.c.orig	2021-01-31 03:36:55 UTC
+++ src/app/main.c
@@ -75,87 +75,22 @@ gchar *find_config_file() {
 	gboolean shortcuts;
 	glong pathmax;
 
-//	We try:
-//	1. in the current directory. (./OPTION_FILE = ./geomorphrc)
-//	2. if not found, we try ./DEF_DIR_NAME/OPTION_FILE (./geomorph/geomorphrc)
-//	3. if not found, we try $HOME/OPTION_FILE (~/geomorphrc)
-//	4. if not found, we try in $HOME/DEF_DIR_NAME (~/geomorph/geomorphrc) 
-//	--> if OPTION_FILE was not found, and 
-//	if $HOME/DEF_DIR_NAME doesn't exist, we create the required files
-//	The directory where OPTION_FILE is found becomes the default one (DEF_DIR)
+	default_dir = concat_dname_fname(getenv("HOME"), DEF_DIR_NAME);
+	path_n_file = path_n_file = concat_dname_fname(default_dir, OPTION_FILE);
 
-	// Try ./OPTION_FILE
-	pathmax = get_pathmax();
-	default_dir = (gchar *) x_malloc(pathmax*sizeof(gchar),"gchar - default_dir in main.c");
-	dummy = (gchar *) getcwd(default_dir,pathmax);
-// printf("Dummy: %p; Current dir name for config file: %p;\n", dummy, default_dir);
-	path_n_file = concat_dname_fname(dummy,OPTION_FILE);
-	if (!filexists(path_n_file)) { // Try ./DEF_DIR_NAME/OPTION_FILE
-		dummy = default_dir;
-		default_dir = concat_dname_fname(dummy,DEF_DIR_NAME);
-		x_free(dummy);
-		dummy = NULL;
-		if (path_n_file)
-			x_free(path_n_file);
-		path_n_file = concat_dname_fname(default_dir,OPTION_FILE);
-		if (!filexists(path_n_file)) { // Try in the home directory - ~/OPTION_FILE
-			x_free(default_dir);
-#ifdef _WIN32
-			default_dir = get_windows_home();
-#else
-			default_dir = getenv("HOME");
-#endif
-			if (path_n_file)
-				x_free(path_n_file);
-			path_n_file = concat_dname_fname(default_dir, OPTION_FILE);
-			if (!filexists(path_n_file)) { // Try ~/DEFAULT_DIR/OPTION_FILE
-				dummy = default_dir;				
-				default_dir = concat_dname_fname(dummy,DEF_DIR_NAME);
-				// Here we don't free dummy because it comes from getenv
-				if (path_n_file) 
-					x_free(path_n_file);
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
-					sprintf(buf,_("Creation of the default working directory %s?"),default_dir);
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
+	if (directory_exists(default_dir)) {
+		if (!filexists(path_n_file)) {
+			create_config_file(path_n_file);
 		}
+	} else {
+		command = concat_dname_fname(get_data_dir(),"install-step1-dir");
+		if (system(command))
+			my_msg(_("Fatal error during the creation of the default working directory"),ABORT);
+		if (command) free(command);
+		create_config_file(path_n_file);
 	}
-	dummy = default_dir;
-	default_dir = add_filesep(dummy);
-	if (dummy != default_dir)
-		x_free(dummy);
-	return default_dir;
+	if (path_n_file) free(path_n_file);
+	return add_filesep(default_dir);
 }
 
 int main( int   argc,
