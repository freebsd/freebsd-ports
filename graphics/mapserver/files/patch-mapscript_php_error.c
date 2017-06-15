--- mapscript/php/error.c.orig	2016-09-21 17:57:25 UTC
+++ mapscript/php/error.c
@@ -31,6 +31,15 @@
 
 #include "php_mapscript.h"
 
+#undef ZVAL_STRING
+#define ZVAL_STRING(z, s, duplicate) do {       \
+                const char *__s=(s);                            \
+                zval *__z = (z);                                        \
+                Z_STRLEN_P(__z) = strlen(__s);          \
+                Z_STRVAL_P(__z) = (duplicate?estrndup(__s, Z_STRLEN_P(__z)):(char*)__s);\
+                Z_TYPE_P(__z) = IS_STRING;                      \
+        } while (0)
+
 zend_class_entry *mapscript_ce_error;
 
 ZEND_BEGIN_ARG_INFO_EX(error___get_args, 0, 0, 1)
