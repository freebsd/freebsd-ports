--- jq.c.orig	2014-11-20 06:16:09 UTC
+++ jq.c
@@ -10,8 +10,8 @@
 
 #include "php_jq.h"
 
-#include "jq/jq.h"
-#include "jq/version.h"
+#include "jq.h"
+#include "version.h"
 
 ZEND_DECLARE_MODULE_GLOBALS(jq)
 
