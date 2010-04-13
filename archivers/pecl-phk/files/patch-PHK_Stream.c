--- ./PHK_Stream.c.orig	2010-04-12 20:07:31.000000000 -0400
+++ ./PHK_Stream.c	2010-04-12 20:07:39.000000000 -0400
@@ -921,7 +921,7 @@
 
 /*---------------------------------------------------------------*/
 
-static ZEND_BEGIN_ARG_INFO_EX(PHK_Stream_get_file_arginfo, 0, 0, 6)
+ZEND_BEGIN_ARG_INFO_EX(PHK_Stream_get_file_arginfo, 0, 0, 6)
 ZEND_ARG_INFO(0, dir)
 ZEND_ARG_INFO(0, uri)
 ZEND_ARG_INFO(0, mnt)
