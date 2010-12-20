--- src/jrd/os/config_root.h.orig	Tue Aug 15 22:57:33 2006
+++ src/jrd/os/config_root.h	Tue Aug 15 22:57:53 2006
@@ -76,7 +76,7 @@
 	{
 		GetRoot();
 		install_dir = root_dir;
-		config_file = root_dir + string(CONFIG_FILE);
+		config_file = string(FB_CONF_PREFIX) + PathUtils::dir_sep + string(CONFIG_FILE);
 	}
 
 
