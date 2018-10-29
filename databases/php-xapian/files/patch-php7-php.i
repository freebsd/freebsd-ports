--- php7/php.i.orig	2018-10-26 05:08:02 UTC
+++ php7/php.i
@@ -177,9 +177,13 @@ fail: // Label which SWIG_PHP_Error need
 %typemap(out) std::pair<Xapian::TermIterator, Xapian::TermIterator> {
 
     ZVAL_NEW_ARR($result);
+#if PHP_VERSION_ID >= 70300
+    array_init($result);
+#else
     if (array_init($result) == FAILURE) {
 	SWIG_PHP_Error(E_ERROR, "array_init failed");
     }
+#endif
 
     for (Xapian::TermIterator i = $1.first; i != $1.second; ++i) {
 	/* We have to cast away const here because the PHP API is rather
@@ -198,9 +202,13 @@ fail: // Label which SWIG_PHP_Error need
 
 %typemap(directorin) (size_t num_tags, const std::string tags[]) {
     ZVAL_NEW_ARR($input);
+#if PHP_VERSION_ID >= 70300
+    array_init($input);
+#else
     if (array_init($input) == FAILURE) {
 	SWIG_PHP_Error(E_ERROR, "array_init failed");
     }
+#endif
 
     for (size_t i = 0; i != num_tags; ++i) {
 	const string & term = tags[i];
