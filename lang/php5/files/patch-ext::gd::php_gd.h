--- ext/gd/php_gd.h.orig	Mon Mar 31 10:49:30 2003
+++ ext/gd/php_gd.h	Sat Jun 28 15:47:56 2003
@@ -40,6 +40,8 @@
 #define PHP_GDIMG_TYPE_GD       8
 #define PHP_GDIMG_TYPE_GD2      9
 #define PHP_GDIMG_TYPE_GD2PART 10
+#define PHP_GDIMG_TYPE_GIFANIMBEGIN 11
+#define PHP_GDIMG_TYPE_GIFANIMADD 12
 
 #ifdef PHP_WIN32
 #define PHP_GD_API __declspec(dllexport)
@@ -137,6 +139,9 @@
 PHP_FUNCTION(imagefontheight);
 
 PHP_FUNCTION(imagegif );
+PHP_FUNCTION(imagegifanimbegin);
+PHP_FUNCTION(imagegifanimadd);
+PHP_FUNCTION(imagegifanimend);
 PHP_FUNCTION(imagejpeg );
 PHP_FUNCTION(imagepng);
 PHP_FUNCTION(imagewbmp);
