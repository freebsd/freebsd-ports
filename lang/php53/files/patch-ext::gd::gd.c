--- ext/gd/gd.c.orig	Wed Jun  4 02:22:30 2003
+++ ext/gd/gd.c	Sat Jun 28 15:47:56 2003
@@ -206,6 +206,11 @@
 #ifdef HAVE_GD_GIF_CREATE
 	PHP_FE(imagegif,								NULL)
 #endif
+#ifdef HAVE_GD_GIF_ANIM
+	PHP_FE(imagegifanimbegin,						NULL)
+	PHP_FE(imagegifanimadd,							NULL)
+	PHP_FE(imagegifanimend,							NULL)
+#endif
 #ifdef HAVE_GD_JPG
 	PHP_FE(imagejpeg,								NULL)
 #endif
@@ -1707,11 +1712,35 @@
 #ifdef HAVE_GD_GIF_CTX
 	_php_image_output_ctx(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHP_GDIMG_TYPE_GIF, "GIF", gdImageGifCtx);
 #else
+
+#ifdef HAVE_GD_BUNDLED
+#error "I really think there should be ctx version of imagegif in the bundled GD library.  Fix the configuration."
+#endif
+
 	_php_image_output(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHP_GDIMG_TYPE_GIF, "GIF", gdImageGif);
 #endif
 }
 /* }}} */
 #endif /* HAVE_GD_GIF_CREATE */
+
+#ifdef HAVE_GD_GIF_ANIM
+/* {{{ proto int imagegifanimbegin(int im [, string filename [, int GlobalColormap [, int Loops]]])
+   Begin GIF animation.  Image parameter is only used for size and colormap,
+   all animation frames must be added separately. */
+PHP_FUNCTION(imagegifanimbegin)
+{
+	_php_image_output_ctx(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHP_GDIMG_TYPE_GIFANIMBEGIN, "GIF", gdImageGifAnimBeginCtx);
+}
+/* }}} */
+
+/* {{{ proto int imagegifanimadd(int im [, string filename [, int LocalColormap [, LeftOfs [, int TopOfs [, int Delay [, int Disposal]]]]]])
+   Append GIF image to animation */
+PHP_FUNCTION(imagegifanimadd)
+{
+	_php_image_output_ctx(INTERNAL_FUNCTION_PARAM_PASSTHRU, PHP_GDIMG_TYPE_GIFANIMADD, "GIF", gdImageGifAnimAddCtx);
+}
+/* }}} */
+#endif /* HAVE_GD_GIF_ANIM */
 
 #ifdef HAVE_GD_PNG
 /* {{{ proto int imagepng(int im [, string filename])
