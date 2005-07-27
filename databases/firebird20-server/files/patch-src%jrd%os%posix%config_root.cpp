--- src/jrd/os/posix/config_root.cpp.orig	Mon Jul 25 15:19:18 2005
+++ src/jrd/os/posix/config_root.cpp	Mon Jul 25 15:19:49 2005
@@ -152,6 +152,6 @@
 
 const char *ConfigRoot::getConfigFile() const
 {
-	static string file = root_dir + string(CONFIG_FILE);
+	static string file = string(FB_CONF_PREFIX) + PathUtils::dir_sep + string(CONFIG_FILE);
 	return file.c_str();
 }
