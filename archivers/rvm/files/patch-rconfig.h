--- rconfig.h.orig	Sun May  9 07:57:35 2004
+++ rconfig.h	Sat Aug 21 01:55:46 2004
@@ -259,7 +259,7 @@
 	action_type m_action;
 	bool m_default;
 	class timestamp m_timestamp;
-	class cfgfiles_type m_cfgfiles;
+	cfgfiles_type m_cfgfiles;
 	std::string m_link_catalog_dir;
 	std::string m_log_dir;
 	std::string m_rsync_local_path;
