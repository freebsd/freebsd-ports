--- src/flared/ini_option.h.orig	2009-10-09 19:08:47.000000000 +0900
+++ src/flared/ini_option.h	2010-05-30 00:33:49.304567301 +0900
@@ -26,6 +26,7 @@
 
 	int					_back_log;
 	string			_config_path;
+	string			_pid_path;
 	bool				_daemonize;
 	string			_data_dir;
 	string			_index_server_name;
@@ -84,6 +85,7 @@
 
 	int get_back_log() { return this->_back_log; };
 	string get_config_path() { return this->_config_path; };
+	string get_pid_path() { return this->_pid_path; };
 	bool is_daemonize() { return this->_daemonize; };
 	string get_data_dir() { return this->_data_dir; };
 	string get_index_server_name() { return this->_index_server_name; };
