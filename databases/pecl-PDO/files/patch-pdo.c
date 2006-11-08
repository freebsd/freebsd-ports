--- pdo.c.orig	Wed Nov  8 09:14:17 2006
+++ pdo.c	Wed Nov  8 09:14:45 2006
@@ -74,7 +74,7 @@
 		}
 	}
 #endif
-#if (PHP_MAJOR_VERSION < 6)
+#if (PHP_MAJOR_VERSION <= 5) && (PHP_MINOR_VERSION < 2)
 	return zend_exception_get_default();
 #else
 	return zend_exception_get_default(TSRMLS_C);
