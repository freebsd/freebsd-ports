--- simsys.cc.orig	2019-12-03 10:58:15 UTC
+++ simsys.cc
@@ -357,7 +357,7 @@ char const *dr_query_homedir()
 	find_directory(B_USER_DIRECTORY, &userDir);
 	sprintf(buffer, "%s/simutrans", userDir.Path());
 #else
-	sprintf(buffer, "%s/simutrans", getenv("HOME"));
+	sprintf(buffer, "%s/.simutrans", getenv("HOME"));
 #endif
 
 	// create directory and subdirectories
