--- gd.c.orig	2019-08-06 06:54:09 UTC
+++ gd.c
@@ -73,7 +73,7 @@ static int le_gd, le_gd_font;
 # include FT_FREETYPE_H
 #endif
 
-#if defined(HAVE_GD_XPM) && defined(HAVE_GD_BUNDLED)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM) && defined(HAVE_GD_BUNDLED)
 # include "X11/xpm.h"
 #endif
 
@@ -322,7 +322,7 @@ ZEND_BEGIN_ARG_INFO(arginfo_imagecreatef
 	ZEND_ARG_INFO(0, filename)
 ZEND_END_ARG_INFO()
 
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 ZEND_BEGIN_ARG_INFO(arginfo_imagecreatefromxpm, 0)
 	ZEND_ARG_INFO(0, filename)
 ZEND_END_ARG_INFO()
@@ -935,7 +935,7 @@ static const zend_function_entry gd_func
 #endif
 	PHP_FE(imagecreatefromwbmp,						arginfo_imagecreatefromwbmp)
 	PHP_FE(imagecreatefromxbm,						arginfo_imagecreatefromxbm)
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 	PHP_FE(imagecreatefromxpm,						arginfo_imagecreatefromxpm)
 #endif
 	PHP_FE(imagecreatefromgd,						arginfo_imagecreatefromgd)
@@ -1312,7 +1312,7 @@ PHP_MINFO_FUNCTION(gd)
 #endif
 #endif
 	php_info_print_table_row(2, "WBMP Support", "enabled");
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 	php_info_print_table_row(2, "XPM Support", "enabled");
 #if defined(HAVE_GD_BUNDLED)
 	{
@@ -1371,7 +1371,7 @@ PHP_FUNCTION(gd_info)
 	add_assoc_bool(return_value, "PNG Support", 0);
 #endif
 	add_assoc_bool(return_value, "WBMP Support", 1);
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 	add_assoc_bool(return_value, "XPM Support", 1);
 #else
 	add_assoc_bool(return_value, "XPM Support", 0);
@@ -2213,7 +2213,7 @@ PHP_FUNCTION(imagetypes)
 	ret |= PHP_IMG_PNG;
 #endif
 	ret |= PHP_IMG_WBMP;
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 	ret |= PHP_IMG_XPM;
 #endif
 #ifdef HAVE_GD_WEBP
@@ -2487,7 +2487,7 @@ static void _php_image_create_from(INTER
 			case PHP_GDIMG_TYPE_GD2PART:
 				im = (*func_p)(fp, srcx, srcy, width, height);
 				break;
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 			case PHP_GDIMG_TYPE_XPM:
 				im = gdImageCreateFromXpm(file);
 				break;
@@ -2569,7 +2569,7 @@ PHP_FUNCTION(imagecreatefromxbm)
 }
 /* }}} */
 
-#if defined(HAVE_GD_XPM)
+#if defined(HAVE_XPM) && defined(HAVE_GD_XPM)
 /* {{{ proto resource imagecreatefromxpm(string filename)
    Create a new image from XPM file or URL */
 PHP_FUNCTION(imagecreatefromxpm)
