--- ./PHK.c.orig	2010-04-12 20:08:05.000000000 -0400
+++ ./PHK.c	2010-04-12 20:08:15.000000000 -0400
@@ -1086,7 +1086,7 @@
 /* }}} */
 /*---------------------------------------------------------------*/
 
-static ZEND_BEGIN_ARG_INFO_EX(PHK_prolog_arginfo, 0, 0, 3)
+ZEND_BEGIN_ARG_INFO_EX(PHK_prolog_arginfo, 0, 0, 3)
 ZEND_ARG_INFO(0, file)
 ZEND_ARG_INFO(1, cmd)
 ZEND_ARG_INFO(1, ret)
