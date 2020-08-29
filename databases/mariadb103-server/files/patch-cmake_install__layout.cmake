--- cmake/install_layout.cmake.orig	2020-05-09 19:27:56 UTC
+++ cmake/install_layout.cmake
@@ -128,8 +128,8 @@ SET(INSTALL_SUPPORTFILESDIR_STANDALONE  "support-files
 SET(INSTALL_MYSQLDATADIR_STANDALONE     "data")
 
 SET(INSTALL_UNIX_ADDRDIR_STANDALONE     "/tmp/mysql.sock")
-SET(INSTALL_PAMDIR_STANDALONE           "share")
-SET(INSTALL_PAMDATADIR_STANDALONE       "share")
+SET(INSTALL_PAMDIR_STANDALONE           "lib/mysql/plugin")
+SET(INSTALL_PAMDATADIR_STANDALONE       "etc/mysql")
 #
 # RPM layout
 #
