--- src/flared/flared.cc.orig	2009-10-09 19:08:47.000000000 +0900
+++ src/flared/flared.cc	2010-05-30 00:39:38.664817940 +0900
@@ -116,6 +116,7 @@
 	log_notice("application startup in progress...", 0);
 	log_notice("  back_log:               %d", ini_option_object().get_back_log());
 	log_notice("  config_path:            %s", ini_option_object().get_config_path().c_str());
+	log_notice("  pid_path:               %s", ini_option_object().get_pid_path().c_str());
 	log_notice("  daemonize:              %s", ini_option_object().is_daemonize() ? "true" : "false");
 	log_notice("  data_dir:               %s", ini_option_object().get_data_dir().c_str());
 	log_notice("  index_server_name:      %s", ini_option_object().get_index_server_name().c_str());
@@ -309,7 +310,9 @@
 
 // {{{ protected methods
 string flared::_get_pid_path() {
-	return ini_option_object().get_data_dir() + "/" + this->_ident + ".pid";
+	return ini_option_object().get_pid_path().empty() ?
+					ini_option_object().get_data_dir() + "/" + this->_ident + ".pid" :
+					ini_option_object().get_pid_path();
 };
 // }}}
 
