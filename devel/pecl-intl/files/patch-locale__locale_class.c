--- ./locale/locale_class.c.orig	2010-04-13 10:34:14.000000000 -0400
+++ ./locale/locale_class.c	2010-04-13 10:34:27.000000000 -0400
@@ -35,29 +35,24 @@
  *        approptiate 'locale_XX_args' for the procedural API!
  */
 
-static
 ZEND_BEGIN_ARG_INFO_EX( locale_0_args, 0, 0, 0 )
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX( locale_1_arg, 0, 0, 1 )
 	ZEND_ARG_INFO( 0, arg1 )
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX( locale_2_args, 0, 0, 2 )
 	ZEND_ARG_INFO( 0, arg1 )
 	ZEND_ARG_INFO( 0, arg2 )
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX( locale_3_args, 0, 0, 3 )
         ZEND_ARG_INFO( 0, arg1 )
         ZEND_ARG_INFO( 0, arg2 )
         ZEND_ARG_INFO( 0, arg3 )
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX( locale_4_args, 0, 0, 4 )
         ZEND_ARG_INFO( 0, arg1 )
         ZEND_ARG_INFO( 0, arg2 )
