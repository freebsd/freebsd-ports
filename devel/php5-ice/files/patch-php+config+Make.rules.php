--- php/config/Make.rules.php.orig	2010-06-03 18:48:34.000000000 +0200
+++ php/config/Make.rules.php	2010-07-30 14:43:46.000000000 +0200
@@ -12,7 +12,9 @@
 # if it does not exist.
 #
 
-prefix			?= /opt/Ice-$(VERSION)
+ICE_HOME		= /usr/local
+
+prefix			?= /usr/local/lib/php/$(PHP_EXT_DIR)
 
 #
 # The "root directory" for runpath embedded in executables. Can be unset
@@ -25,7 +27,7 @@
 # Otherwise the Ice extension is built with debug information.
 #
 
-#OPTIMIZE		= yes
+OPTIMIZE		= yes
 
 #
 # Define LP64 as yes if you want to build in 64 bit mode on a platform
@@ -54,7 +56,7 @@
 # PHP_INCLUDE_DIR and PHP_LIB_DIR.
 #
 
-PHP_HOME		?= /opt/php
+PHP_HOME		?= /usr/local
 
 #
 # Verifies the PHP_HOME is valid and attempts to adjust for platform variances
@@ -100,8 +102,8 @@
 endif
 
 libdir			= $(top_srcdir)/lib
-install_phpdir		= $(prefix)/php
-install_libdir		= $(prefix)/php
+install_phpdir		= $(prefix)
+install_libdir		= $(prefix)
 
 #
 # Platform specific definitions
