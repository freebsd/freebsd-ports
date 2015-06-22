--- cmake/install_layout.cmake.orig	2015-02-25 21:09:49 UTC
+++ cmake/install_layout.cmake
@@ -112,14 +112,14 @@ FILE(GLOB plugin_tests
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
