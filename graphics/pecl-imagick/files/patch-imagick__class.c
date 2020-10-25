--- imagick_class.c.orig	2020-10-25 08:02:54 UTC
+++ imagick_class.c
@@ -12006,7 +12006,9 @@ PHP_METHOD(imagick, setprogressmonitor)
 
 	callback = (php_imagick_callback *) emalloc(sizeof(php_imagick_callback));
 
+#if PHP_VERSION_ID < 80000
 	TSRMLS_SET_CTX(callback->thread_ctx);
+#endif
 	//We can't free the previous callback as we can't guarantee that
 	//ImageMagick won't use it at some point. There is no 'unbind' function
 	//for previously set 'MagickSetImageProgressMonitor'
