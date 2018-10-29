--- php7/php7/xapian_wrap.cc.orig	2018-10-26 05:12:41 UTC
+++ php7/php7/xapian_wrap.cc
@@ -2533,9 +2533,13 @@ std::string SwigDirector_Compactor::reso
   
   {
     ZVAL_NEW_ARR(&args[1]);
+#if PHP_VERSION_ID >= 70300
+    array_init(&args[1]);
+#else
     if (array_init(&args[1]) == FAILURE) {
       SWIG_PHP_Error(E_ERROR, "array_init failed");
     }
+#endif
     
     for (size_t i = 0; i != num_tags; ++i) {
       const string & term = tags[i];
@@ -16756,9 +16760,13 @@ ZEND_NAMED_FUNCTION(_wrap_Enquire_get_ma
   }
   {
     ZVAL_NEW_ARR(return_value);
+#if PHP_VERSION_ID >= 70300
+    array_init(return_value);
+#else
     if (array_init(return_value) == FAILURE) {
       SWIG_PHP_Error(E_ERROR, "array_init failed");
     }
+#endif
     
     for (Xapian::TermIterator i = (&result)->first; i != (&result)->second; ++i) {
       /* We have to cast away const here because the PHP API is rather
