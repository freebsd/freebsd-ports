--- extconf.rb.orig	Sun Mar  6 22:41:34 2005
+++ extconf.rb	Sun Mar  6 22:41:59 2005
@@ -13,6 +13,7 @@
 require 'mkmf-gnome2'
 
 PKGConfig.have_package('gobject-2.0') or exit 1
+PKGConfig.have_package('gthread-2.0') or exit 1
 
 setup_win32(PACKAGE_NAME)
 
