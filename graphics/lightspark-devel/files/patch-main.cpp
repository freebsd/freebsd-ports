--- main.cpp.orig	2010-09-09 17:10:38.000000000 +0400
+++ main.cpp	2010-09-16 00:15:03.000000000 +0400
@@ -182,7 +182,9 @@
 	//When running in a local sandbox, set the root URL to the current working dir
 	else if(sandboxType != Security::REMOTE)
 	{
-		char * cwd = get_current_dir_name();
+		char cwd[1024];
+		if (getcwd(cwd, 1024) == NULL)
+			exit(-1);
 		tiny_string cwdStr = tiny_string("file://") + tiny_string(cwd, true);
 		free(cwd);
 		cwdStr += "/";
