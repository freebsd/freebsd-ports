--- src/common/slogger.cc.orig	2019-01-28 19:24:32 UTC
+++ src/common/slogger.cc
@@ -86,7 +86,7 @@ void lzfs::drop_all_logs() {
 bool lzfs::add_log_syslog() {
 #ifndef _WIN32
 	try {
-		spdlog::syslog_logger("syslog");
+		spdlog::syslog_logger_mt("syslog");
 		return true;
 	} catch (const spdlog::spdlog_ex &e) {
 		lzfs_pretty_syslog(LOG_ERR, "Adding syslog log failed: %s", e.what());
