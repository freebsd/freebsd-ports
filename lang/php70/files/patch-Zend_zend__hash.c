--- Zend/zend_hash.c.orig	2017-12-13 20:20:30 UTC
+++ Zend/zend_hash.c
@@ -1573,7 +1573,7 @@ ZEND_API void ZEND_FASTCALL zend_hash_ap
 }
 
 
-ZEND_API void ZEND_FASTCALL zend_hash_apply_with_arguments(HashTable *ht, apply_func_args_t apply_func, int num_args, ...)
+ZEND_API void zend_hash_apply_with_arguments(HashTable *ht, apply_func_args_t apply_func, int num_args, ...)
 {
 	uint32_t idx;
 	Bucket *p;
