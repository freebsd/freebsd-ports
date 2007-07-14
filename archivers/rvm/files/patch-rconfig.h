--- ./rconfig.h.orig	2006-06-23 17:27:50.000000000 +0200
+++ ./rconfig.h	2007-07-14 11:38:49.000000000 +0200
@@ -266,7 +266,7 @@
 	action_type m_action;
 	bool m_default;
 	class timestamp m_timestamp;
-	class cfgfiles_type m_cfgfiles;
+	cfgfiles_type m_cfgfiles;
 	std::string m_link_catalog_dir;
 	std::string m_log_dir;
 	std::string m_rsync_local_path;
@@ -366,7 +366,7 @@
 	bool m_default_context;
 
 	const std::string location(void);
-	void job_parser::read_job(const std::string& a_path);
+	void read_job(const std::string& a_path);
 
 	void parse(void);
 	void parse_archive_path(const std::string& a_value);
