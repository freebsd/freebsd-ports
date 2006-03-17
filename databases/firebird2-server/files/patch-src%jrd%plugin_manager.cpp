--- src/jrd/plugin_manager.cpp.orig	Wed Mar 15 14:25:42 2006
+++ src/jrd/plugin_manager.cpp	Wed Mar 15 14:39:12 2006
@@ -47,9 +47,7 @@
 void PluginManager::loadAllPlugins()
 {
 	Firebird::list<Path>::iterator pathItr;
-	char fb_lib_path[MAXPATHLEN];
-	gds__prefix(fb_lib_path, "");
-	Firebird::string fbLibPath(fb_lib_path);
+	Firebird::string fbLibPath(FB_LIBEXEC_PREFIX);
 	Firebird::string checkDir;
 	
 	for(pathItr = searchPaths.begin(); pathItr != searchPaths.end(); ++pathItr)
@@ -114,9 +112,7 @@
 
 PluginManager::Module *PluginManager::loadPluginModule(const Firebird::string& name)
 {
-	char fb_lib_path[MAXPATHLEN];
-	gds__prefix(fb_lib_path, "");
-	Firebird::string fbLibPath(fb_lib_path);
+	Firebird::string fbLibPath(FB_LIBEXEC_PREFIX);
 	Firebird::string checkPath;
 	Firebird::list<Path>::iterator itr;
 	
