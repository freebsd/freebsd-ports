--- mustache_data.cpp.orig	2019-05-27 21:52:06 UTC
+++ mustache_data.cpp
@@ -136,7 +136,7 @@ static zend_always_inline void mustache_
 {
   HashTable * data_hash = NULL;
   long data_count = 0;
-  ulong key_nindex = 0;
+  zend_ulong key_nindex = 0;
   zend_string * key;
   std::string ckey;
   zval * data_entry = NULL;
@@ -228,7 +228,7 @@ static zend_always_inline void mustache_
 static zend_always_inline void mustache_data_from_object_properties_zval(mustache::Data * node, zval * current)
 {
   HashTable * data_hash = NULL;
-  ulong key_nindex = 0;
+  zend_ulong key_nindex = 0;
   zend_string * key;
   std::string ckey;
   zval * data_entry = NULL;
@@ -311,7 +311,7 @@ static zend_always_inline void mustache_
 static zend_always_inline void mustache_data_from_object_functions_zval(mustache::Data * node, zval * current)
 {
   HashTable * data_hash = NULL;
-  ulong key_nindex = 0;
+  zend_ulong key_nindex = 0;
   zend_string * key;
   std::string ckey;
   zval * data_entry = NULL;
