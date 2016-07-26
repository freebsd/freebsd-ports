--- removefile.c.orig	2004-04-01 13:26:19 UTC
+++ removefile.c
@@ -111,7 +111,7 @@ static void remove_dirname(int root_len,
     DIR *dir = opendir(".");
     if (dir) {
       /* xmms uses absolute paths */
-      char *pwd = get_current_dir_name();
+      char *pwd = getcwd(NULL,PATH_MAX);
       struct dirent *entry;
       struct stat file_stat;
 
@@ -189,7 +189,7 @@ void remove_file(gint session, char *fil
       gint *remove_pos = (gint*) malloc(list_size*sizeof(gint));
 
       if (remove_pos) {
-	char *pwd = get_current_dir_name();
+	char *pwd = getcwd(NULL,PATH_MAX);
 	int root_len = strlen(pwd)+1; /* +1: jump appended / */
 	gint i;
 
