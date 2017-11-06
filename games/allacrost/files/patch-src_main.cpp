--- src/main.cpp.orig	2010-05-17 22:52:57 UTC
+++ src/main.cpp
@@ -364,11 +364,9 @@ int main(int argc, char *argv[]) {
 			// Now the program should be in app/Contents
 			path.append ("/Resources/");
 			chdir(path.c_str());
-		#elif (defined(__linux__) || defined(__FreeBSD__)) && !defined(RELEASE_BUILD)
-			// Look for data files in DATADIR only if they are not available in the
-			// current directory.
-			if (ifstream("dat/config/settings.lua") == NULL)
-				chdir(DATADIR);
+		#elif (defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)) && !defined(RELEASE_BUILD)
+			// Always look into datadir
+			chdir(DATADIR);
 		#endif
 
 		// Initialize the random number generator (note: 'unsigned int' is a required usage in this case)
