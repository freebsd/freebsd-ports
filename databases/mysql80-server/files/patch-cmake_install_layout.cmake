--- cmake/install_layout.cmake.orig	2019-12-09 19:53:17 UTC
+++ cmake/install_layout.cmake
@@ -41,6 +41,10 @@
 #    Build with prefix=/usr/local/mysql, create tarball with install prefix="."
 #    and relative links.
 #
+#  FREEBSD
+#    Build with prefix=/usr/local, create tarball with install prefix="."
+#    and relative links.
+#
 # To force a directory layout, use -DINSTALL_LAYOUT=<layout>.
 #
 # The default is STANDALONE.
@@ -80,7 +84,7 @@ IF(NOT INSTALL_LAYOUT)
 ENDIF()
 
 SET(INSTALL_LAYOUT "${DEFAULT_INSTALL_LAYOUT}"
-  CACHE STRING "Installation directory layout. Options are: TARGZ (as in tar.gz installer), STANDALONE, RPM, DEB, SVR4"
+  CACHE STRING "Installation directory layout. Options are: TARGZ (as in tar.gz installer), STANDALONE, FREEBSD, RPM, DEB, SVR4"
   )
 
 IF(UNIX)
@@ -98,7 +102,7 @@ IF(UNIX)
       CACHE PATH "install prefix" FORCE)
   ENDIF()
   SET(VALID_INSTALL_LAYOUTS
-    "RPM" "DEB" "SVR4" "TARGZ" "STANDALONE")
+    "RPM" "DEB" "SVR4" "TARGZ" "FREEBSD" "STANDALONE")
   LIST(FIND VALID_INSTALL_LAYOUTS "${INSTALL_LAYOUT}" ind)
   IF(ind EQUAL -1)
     MESSAGE(FATAL_ERROR "Invalid INSTALL_LAYOUT parameter:${INSTALL_LAYOUT}."
@@ -171,6 +175,32 @@ SET(INSTALL_MYSQLKEYRINGDIR_STANDALONE  "keyring")
 SET(INSTALL_SECURE_FILE_PRIVDIR_STANDALONE ${secure_file_priv_path})
 
 #
+# FREEBSD layout
+#
+SET(INSTALL_BINDIR_FREEBSD           "bin")
+SET(INSTALL_SBINDIR_FREEBSD          "bin")
+#
+SET(INSTALL_LIBDIR_FREEBSD           "lib")
+SET(INSTALL_PRIV_LIBDIR_FREEBSD      "lib/private")
+SET(INSTALL_PLUGINDIR_FREEBSD        "lib/plugin")
+#
+SET(INSTALL_INCLUDEDIR_FREEBSD       "include")
+#
+SET(INSTALL_DOCDIR_FREEBSD           "docs")
+SET(INSTALL_DOCREADMEDIR_FREEBSD     ".")
+SET(INSTALL_MANDIR_FREEBSD           "man")
+SET(INSTALL_INFODIR_FREEBSD          "docs")
+#
+SET(INSTALL_SHAREDIR_FREEBSD         "share")
+SET(INSTALL_MYSQLSHAREDIR_FREEBSD    "share")
+SET(INSTALL_MYSQLTESTDIR_FREEBSD     "mysql-test")
+SET(INSTALL_SUPPORTFILESDIR_FREEBSD  "support-files")
+#
+SET(INSTALL_MYSQLDATADIR_FREEBSD     "data")
+SET(INSTALL_MYSQLKEYRINGDIR_FREEBSD  "keyring")
+SET(INSTALL_SECURE_FILE_PRIVDIR_FREEBSD ${secure_file_priv_path})
+
+#
 # TARGZ layout
 #
 SET(INSTALL_BINDIR_TARGZ           "bin")
@@ -369,7 +399,7 @@ ENDIF()
 SET(ROUTER_INSTALL_LAYOUT "${DEFAULT_ROUTER_INSTALL_LAYOUT}"
   CACHE
   STRING
-  "Installation directory layout. Options are: STANDALONE RPM DEB SVR4 TARGZ")
+  "Installation directory layout. Options are: STANDALONE FREEBSD RPM DEB SVR4 TARGZ")
 
 # If we are shared STANDALONE with the the server, we shouldn't write
 # into the server's data/ as that would create a "schemadir" in
@@ -408,6 +438,18 @@ FOREACH(var
     )
   SET(ROUTER_INSTALL_${var}DIR_TARGZ ${ROUTER_INSTALL_${var}DIR_STANDALONE})
 ENDFOREACH()
+
+#
+# FreeBSD layout
+#
+SET(ROUTER_INSTALL_CONFIGDIR_FREEBSD  "/usr/local/etc/mysqlrouter")
+SET(ROUTER_INSTALL_DATADIR_FREEBSD    "/var/db/mysqlrouter")
+SET(ROUTER_INSTALL_LOGDIR_FREEBSD     "/var/log/mysqlrouter")
+SET(ROUTER_INSTALL_RUNTIMEDIR_FREEBSD "/var/run/mysqlrouter")
+
+SET(ROUTER_INSTALL_BINDIR_FREEBSD     "bin")
+SET(ROUTER_INSTALL_LIBDIR_FREEBSD     "lib/mysql")
+SET(ROUTER_INSTALL_PLUGINDIR_FREEBSD  "lib/mysql/mysqlrouter")
 
 #
 # RPM layout
