--- cmake/install_layout.cmake.orig	2013-12-23 20:24:06.000000000 +0100
+++ cmake/install_layout.cmake	2014-01-31 15:09:54.000000000 +0100
@@ -112,14 +112,14 @@
 #
 # STANDALONE layout
 #
-SET(INSTALL_BINDIR_STANDALONE           "bin")
+SET(INSTALL_BINDIR_STANDALONE           "bin/mysql-connector-c")
 SET(INSTALL_SBINDIR_STANDALONE          "bin")
 SET(INSTALL_SCRIPTDIR_STANDALONE        "scripts")
 #
-SET(INSTALL_LIBDIR_STANDALONE           "lib")
-SET(INSTALL_PLUGINDIR_STANDALONE        "lib/plugin")
+SET(INSTALL_LIBDIR_STANDALONE           "lib/mysql-connector-c")
+SET(INSTALL_PLUGINDIR_STANDALONE        "lib/mysql-connector-cplugin")
 #
-SET(INSTALL_INCLUDEDIR_STANDALONE       "include")
+SET(INSTALL_INCLUDEDIR_STANDALONE       "include/mysql-connector-c")
 #
 SET(INSTALL_DOCDIR_STANDALONE           "docs")
 SET(INSTALL_DOCREADMEDIR_STANDALONE     ".")
