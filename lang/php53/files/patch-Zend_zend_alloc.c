--- Zend/zend_alloc.c	2006/08/10 17:16:24	1.144.2.4
+++ Zend/zend_alloc.c	2006/09/30 17:15:23	1.144.2.5
@@ -328,15 +328,14 @@
 ZEND_API void *_ecalloc(size_t nmemb, size_t size ZEND_FILE_LINE_DC ZEND_FILE_LINE_ORIG_DC)
 {
 	void *p;
-	int final_size = size*nmemb;
-	
+
 	HANDLE_BLOCK_INTERRUPTIONS();
-	p = _emalloc(final_size ZEND_FILE_LINE_RELAY_CC ZEND_FILE_LINE_ORIG_RELAY_CC);
+	p = _safe_emalloc(nmemb, size, 0 ZEND_FILE_LINE_RELAY_CC ZEND_FILE_LINE_ORIG_RELAY_CC);
 	if (!p) {
 		HANDLE_UNBLOCK_INTERRUPTIONS();
 		return (void *) p;
 	}
-	memset(p, 0, final_size);
+	memset(p, 0, size * nmemb);
 	HANDLE_UNBLOCK_INTERRUPTIONS();
 	return p;
 }
