--- src/flarei/flarei.cc.orig	2009-10-09 19:08:47.000000000 +0900
+++ src/flarei/flarei.cc	2010-05-30 00:46:08.682784235 +0900
@@ -106,6 +106,7 @@
 
 	log_notice("application startup in progress...", 0);
 	log_notice("  config_path:            %s", ini_option_object().get_config_path().c_str());
+	log_notice("  pid_path:               %s", ini_option_object().get_pid_path().c_str());
 	log_notice("  daemonize:              %s", ini_option_object().is_daemonize() ? "true" : "false");
 	log_notice("  data_dir:               %s", ini_option_object().get_data_dir().c_str());
 	log_notice("  max_connection:         %d", ini_option_object().get_max_connection());
@@ -253,7 +254,9 @@
 
 // {{{ protected methods
 string flarei::_get_pid_path() {
-	return ini_option_object().get_data_dir() + "/" + this->_ident + ".pid";
+	return ini_option_object().get_pid_path().empty() ?
+					ini_option_object().get_data_dir() + "/" + this->_ident + ".pid" :
+					ini_option_object().get_pid_path();
 };
 // }}}
 
