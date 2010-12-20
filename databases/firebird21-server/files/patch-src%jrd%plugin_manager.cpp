--- src/jrd/plugin_manager.cpp.orig	Tue Aug 15 23:11:04 2006
+++ src/jrd/plugin_manager.cpp	Tue Aug 15 23:12:01 2006
@@ -64,7 +64,7 @@
 void PluginManager::loadAllPlugins()
 {
 	Firebird::PathName checkDir;
-	const Firebird::PathName fbLibPath = Config::getRootDirectory();
+	const Firebird::PathName fbLibPath = FB_LIBEXEC_PREFIX;
 	
 	for (spIterator pathItr = searchPaths.begin(); pathItr != searchPaths.end(); ++pathItr)
 	{
@@ -131,7 +131,7 @@
 PluginManager::Module *PluginManager::loadPluginModule(const Firebird::PathName& name)
 {
 	Firebird::PathName checkPath;
-	const Firebird::PathName fbLibPath = Config::getRootDirectory();
+	const Firebird::PathName fbLibPath = FB_LIBEXEC_PREFIX;
 	
 	// Check to see if the module name was specified as a relative path
 	//	from one of our search paths.  This only makes sense if the name
