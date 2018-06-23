--- src/engine/system.cpp.orig	2010-05-16 23:38:27 UTC
+++ src/engine/system.cpp
@@ -271,7 +271,7 @@ bool SystemEngine::SingletonInitialize()
 	#elif (defined(__linux__) || defined(__FreeBSD__)) && !defined(RELEASE_BUILD)
 		// Look for translation files in LOCALEDIR only if they are not available in the
 		// current directory.
-		if (ifstream("dat/config/settings.lua") == NULL) {
+		if (!ifstream("dat/config/settings.lua")) {
 			bindtextdomain(PACKAGE, LOCALEDIR);
 			bind_textdomain_codeset(PACKAGE, "UTF-8");
 			textdomain(PACKAGE);
