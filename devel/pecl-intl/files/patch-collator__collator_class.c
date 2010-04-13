--- ./collator/collator_class.c.orig	2010-03-15 18:03:30.000000000 -0400
+++ ./collator/collator_class.c	2010-04-13 10:31:54.000000000 -0400
@@ -88,22 +88,18 @@
        modify approptiate 'collator_XX_args' for
        the procedural API.
 */
-static
 ZEND_BEGIN_ARG_INFO_EX( collator_0_args, 0, 0, 0 )
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX( collator_1_arg, 0, 0, 1 )
 	ZEND_ARG_INFO( 0, arg1 )
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX( collator_2_args, 0, 0, 2 )
 	ZEND_ARG_INFO( 0, arg1 )
 	ZEND_ARG_INFO( 0, arg2 )
 ZEND_END_ARG_INFO()
 
-static
 ZEND_BEGIN_ARG_INFO_EX( collator_sort_args, 0, 0, 1 )
 	ZEND_ARG_ARRAY_INFO( 1, arr, 0 )
 	ZEND_ARG_INFO( 0, flags )
