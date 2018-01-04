--- Zend/zend_hash.h.orig	2017-12-13 20:20:24 UTC
+++ Zend/zend_hash.h
@@ -131,7 +131,7 @@ ZEND_API void ZEND_FASTCALL zend_hash_gr
 ZEND_API void ZEND_FASTCALL zend_hash_graceful_reverse_destroy(HashTable *ht);
 ZEND_API void ZEND_FASTCALL zend_hash_apply(HashTable *ht, apply_func_t apply_func);
 ZEND_API void ZEND_FASTCALL zend_hash_apply_with_argument(HashTable *ht, apply_func_arg_t apply_func, void *);
-ZEND_API void ZEND_FASTCALL zend_hash_apply_with_arguments(HashTable *ht, apply_func_args_t apply_func, int, ...);
+ZEND_API void zend_hash_apply_with_arguments(HashTable *ht, apply_func_args_t apply_func, int, ...);
 
 /* This function should be used with special care (in other words,
  * it should usually not be used).  When used with the ZEND_HASH_APPLY_STOP
