--- src/flarei/ini_option.h.orig	2009-10-09 19:08:47.000000000 +0900
+++ src/flarei/ini_option.h	2010-05-30 00:47:47.862009797 +0900
@@ -25,6 +25,7 @@
 	char**			_argv;
 
 	string			_config_path;
+	string			_pid_path;
 	bool				_daemonize;
 	string			_data_dir;
 	string			_log_facility;
@@ -61,6 +62,7 @@
 	int set_args(int argc, char** argv) { this->_argc = argc; this->_argv = argv; return 0; };
 
 	string get_config_path() { return this->_config_path; };
+	string get_pid_path() { return this->_pid_path; };
 	bool is_daemonize() { return this->_daemonize; };
 	string get_data_dir() { return this->_data_dir; };
 	string get_log_facility() { return this->_log_facility; };
