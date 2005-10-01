--- removefile.c.orig	Thu Apr  1 08:26:19 2004
+++ removefile.c	Thu Sep 22 13:41:04 2005
@@ -111,7 +111,7 @@
     DIR *dir = opendir(".");
     if (dir) {
       /* xmms uses absolute paths */
-      char *pwd = get_current_dir_name();
+      char *pwd = getcwd(NULL,PATH_MAX);
       struct dirent *entry;
       struct stat file_stat;
 
@@ -189,7 +189,7 @@
       gint *remove_pos = (gint*) malloc(list_size*sizeof(gint));
 
       if (remove_pos) {
-	char *pwd = get_current_dir_name();
+	char *pwd = getcwd(NULL,PATH_MAX);
 	int root_len = strlen(pwd)+1; /* +1: jump appended / */
 	gint i;
 
