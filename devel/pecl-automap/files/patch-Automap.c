--- ./Automap.c.orig	2010-04-12 16:58:59.000000000 -0400
+++ ./Automap.c	2010-04-12 18:59:40.000000000 -0400
@@ -1617,14 +1617,14 @@
 /* }}} */
 /*---------------------------------------------------------------*/
 
-static ZEND_BEGIN_ARG_INFO_EX(Automap_mount_arginfo, 0, 1, 1)
+ZEND_BEGIN_ARG_INFO_EX(Automap_mount_arginfo, 0, 1, 1)
 ZEND_ARG_INFO(0, path)
 ZEND_ARG_INFO(0, base_dir)
 ZEND_ARG_INFO(0, mnt)
 ZEND_ARG_INFO(0, flags)
 ZEND_END_ARG_INFO()
 
-static ZEND_BEGIN_ARG_INFO_EX(Automap_autoload_hook_arginfo, 0, 0, 1)
+ZEND_BEGIN_ARG_INFO_EX(Automap_autoload_hook_arginfo, 0, 0, 1)
 ZEND_ARG_INFO(0, symbol)
 ZEND_ARG_INFO(0, type)
 ZEND_END_ARG_INFO()
