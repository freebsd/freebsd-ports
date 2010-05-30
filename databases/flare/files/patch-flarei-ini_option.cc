--- src/flarei/ini_option.cc.orig	2009-10-09 19:08:47.000000000 +0900
+++ src/flarei/ini_option.cc	2010-05-30 00:47:23.289629400 +0900
@@ -22,6 +22,7 @@
 		_argc(0),
 		_argv(NULL),
 		_config_path(""),
+		_pid_path(""),
 		_daemonize(false),
 		_data_dir(""),
 		_log_facility(""),
@@ -92,6 +93,9 @@
 	if (opt_var_map.count("config")) {
 		this->_config_path = opt_var_map["config"].as<string>();
 	}
+	if (opt_var_map.count("pid")) {
+		this->_pid_path = opt_var_map["pid"].as<string>();
+	}
 
 	// parse config file
 	if (this->_config_path.empty() == false) {
@@ -293,6 +297,7 @@
 int ini_option::_setup_cli_option(program_options::options_description& option) {
 	option.add_options()
 		("config,f",					program_options::value<string>(),	"path to config file")
+		("pid,p",							program_options::value<string>(),	"path to pid file")
 		("version,v",																						"display version")
 		("help,h",																							"display this help");
 
