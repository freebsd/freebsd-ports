--- mustache_mustache.cpp.orig	2019-05-27 21:52:06 UTC
+++ mustache_mustache.cpp
@@ -231,7 +231,7 @@ bool mustache_parse_partials_param(zval 
         mustache::Node::Partials * partials)
 {
     HashTable * data_hash = NULL;
-    ulong key_nindex = 0;
+    zend_ulong key_nindex = 0;
 
     // Ignore if not an array
     if( array == NULL || Z_TYPE_P(array) != IS_ARRAY ) {
