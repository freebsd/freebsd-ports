--- php/config/Make.rules.php.orig	2015-06-23 15:30:20.000000000 +0000
+++ php/config/Make.rules.php	2015-06-27 19:48:31.900063596 +0000
@@ -108,13 +108,8 @@
 
 libdir		= $(top_srcdir)/lib
 
-ifndef usr_dir_install
-    install_phpdir	= $(prefix)/php
-    install_libdir  	= $(prefix)/php
-else
-    install_phpdir  	= $(prefix)/share/php
-    install_libdir  	= $(shell $(PHP_CONFIG) --extension-dir)
-endif
+install_phpdir  	= $(prefix)/share/pear
+install_libdir  	= $(prefix)/lib/php/$(PHP_EXT_DIR)
 
 ifdef ice_src_dist
     RPATH_DIR	= $(LOADER_PATH)/../../cpp/$(libsubdir)
@@ -172,7 +167,8 @@
 endif
 
 ifeq ($(installphplib),)
-    installphplib	= $(INSTALL) $(1) $(2); \
+    installphplib	= mkdir -p $(2) ; \
+			  $(INSTALL) $(1) $(2); \
 			  chmod a+rx $(2)/$(notdir $(1))
 endif
 
