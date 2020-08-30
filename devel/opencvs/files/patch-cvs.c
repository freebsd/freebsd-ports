--- cvs.c.orig	2016-02-06 22:25:25 UTC
+++ cvs.c
@@ -83,6 +83,7 @@ extern CVSENTRIES *current_list;
 
 struct hash_table created_directories;
 struct hash_table created_cvs_directories;
+struct cvs_var_head cvs_variables;
 
 void
 sighandler(int sig)
@@ -187,8 +188,10 @@ main(int argc, char **argv)
 	struct stat st;
 	char fpath[PATH_MAX];
 
+#ifdef __OpenBSD__
 	if (pledge("stdio rpath wpath cpath fattr proc exec", NULL) == -1)
 		err(1, "pledge");
+#endif
 
 	tzset();
 
