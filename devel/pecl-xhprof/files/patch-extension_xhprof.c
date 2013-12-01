--- xhprof.c.orig	2013-11-13 18:41:35.000000000 +0800
+++ xhprof.c	2013-11-13 18:43:37.000000000 +0800
@@ -28,7 +28,7 @@
 #include "php_ini.h"
 #include "ext/standard/info.h"
 #include "php_xhprof.h"
-#include "zend_extensions.h"
+#include "Zend/zend_extensions.h"
 #include <sys/time.h>
 #include <sys/resource.h>
 #include <stdlib.h>
