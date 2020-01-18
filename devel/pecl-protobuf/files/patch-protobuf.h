--- protobuf.h.orig	2019-12-14 00:46:15 UTC
+++ protobuf.h
@@ -292,7 +292,7 @@
 
 #define PHP_PROTO_HASH_OF(array) Z_ARRVAL_P(&array)
 
-static inline int php_proto_zend_hash_index_update_zval(HashTable* ht, ulong h,
+static inline int php_proto_zend_hash_index_update_zval(HashTable* ht, zend_ulong h,
                                                         zval* pData) {
   void* result = NULL;
   result = zend_hash_index_update(ht, h, pData);
@@ -308,7 +308,7 @@ static inline int php_proto_zend_hash_update(HashTable
   return result != NULL ? SUCCESS : FAILURE;
 }
 
-static inline int php_proto_zend_hash_index_update_mem(HashTable* ht, ulong h,
+static inline int php_proto_zend_hash_index_update_mem(HashTable* ht, zend_ulong h,
                                                    void* pData, uint nDataSize,
                                                    void** pDest) {
   void* result = NULL;
@@ -337,7 +337,7 @@ static inline int php_proto_zend_hash_update_mem(HashT
 }
 
 static inline int php_proto_zend_hash_index_find_zval(const HashTable* ht,
-                                                      ulong h, void** pDest) {
+                                                      zend_ulong h, void** pDest) {
   zval* result = zend_hash_index_find(ht, h);
   if (pDest != NULL) *pDest = result;
   return result != NULL ? SUCCESS : FAILURE;
@@ -351,7 +351,7 @@ static inline int php_proto_zend_hash_find(const HashT
 }
 
 static inline int php_proto_zend_hash_index_find_mem(const HashTable* ht,
-                                                     ulong h, void** pDest) {
+                                                     zend_ulong h, void** pDest) {
   void* result = NULL;
   result = zend_hash_index_find_ptr(ht, h);
   if (pDest != NULL) *pDest = result;
