--- horde_lz4.h.orig	2020-10-25 07:33:13 UTC
+++ horde_lz4.h
@@ -30,4 +30,10 @@ typedef size_t strsize;
 #define HORDE_LZ4_RETSTRL(a,l) RETURN_STRINGL(a,l)
 #endif
 
+#if ZEND_MODULE_API_NO >= 20190128
+#ifndef TSRMLS_CC
+#define TSRMLS_CC
+#endif
+#endif
+
 #endif  /* PHP_HORDE_LZ4_H */
