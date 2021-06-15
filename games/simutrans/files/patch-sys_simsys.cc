--- sys/simsys.cc.orig	2022-01-28 11:17:50 UTC
+++ sys/simsys.cc
@@ -395,7 +395,7 @@ char const *dr_query_homedir()
 #elif defined __ANDROID__
 	tstrncpy(buffer,SDL_GetPrefPath("Simutrans Team","simutrans"),lengthof(buffer));
 #else
-	sprintf(buffer, "%s/simutrans", getenv("HOME"));
+	sprintf(buffer, "%s/.simutrans", getenv("HOME"));
 #endif
 
 	// create directory and subdirectories
