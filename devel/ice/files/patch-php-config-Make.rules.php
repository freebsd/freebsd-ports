--- php/config/Make.rules.php.orig	2013-03-11 15:19:47.000000000 +0000
+++ php/config/Make.rules.php	2013-06-02 14:36:13.744196194 +0000
@@ -100,8 +100,8 @@
 endif
 
 libdir			= $(top_srcdir)/lib
 ifneq ($(prefix), /usr)
-install_phpdir      = $(prefix)/php
-install_libdir      = $(prefix)/php
+install_phpdir		= $(prefix)/share/pear
+install_libdir		= $(prefix)/lib/php/$(PHP_EXT_DIR)
 else

@@ -155,7 +155,8 @@
 endif
 
 ifeq ($(installphplib),)
-    installphplib	= $(INSTALL) $(1) $(2); \
+    installphplib	= mkdir -p $(2) ; \
+			  $(INSTALL) $(1) $(2); \
 			  chmod a+rx $(2)/$(notdir $(1))
 endif
 
