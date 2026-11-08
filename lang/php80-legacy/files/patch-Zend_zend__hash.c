--- Zend/zend_hash.c.orig	2026-10-21 15:33:56 UTC
+++ Zend/zend_hash.c
@@ -119,7 +119,7 @@ static zend_always_inline uint32_t zend_hash_check_siz
 	if (nSize <= HT_MIN_SIZE) {
 		return HT_MIN_SIZE;
 	} else if (UNEXPECTED(nSize >= HT_MAX_SIZE)) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%u * %zu + %zu)", nSize, sizeof(Bucket), sizeof(Bucket));
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (%u * %zu + %zu)", nSize, sizeof(Bucket), sizeof(Bucket));
 	}
 
 #ifdef ZEND_WIN32
@@ -273,6 +273,13 @@ ZEND_API HashTable* ZEND_FASTCALL _zend_new_array_0(vo
 	return ht;
 }
 
+ZEND_API HashTable* ZEND_FASTCALL zend_new_array_singleton(void)
+{
+	HashTable *ht = _zend_new_array_0();
+	ht->nTableSize = 1;
+	return ht;
+}
+
 ZEND_API HashTable* ZEND_FASTCALL _zend_new_array(uint32_t nSize)
 {
 	HashTable *ht = emalloc(sizeof(HashTable));
@@ -304,7 +311,7 @@ static void ZEND_FASTCALL zend_hash_packed_grow(HashTa
 {
 	HT_ASSERT_RC1(ht);
 	if (ht->nTableSize >= HT_MAX_SIZE) {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%u * %zu + %zu)", ht->nTableSize * 2, sizeof(Bucket), sizeof(Bucket));
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (%u * %zu + %zu)", ht->nTableSize * 2, sizeof(Bucket), sizeof(Bucket));
 	}
 	ht->nTableSize += ht->nTableSize;
 	HT_SET_DATA_ADDR(ht, perealloc2(HT_GET_DATA_ADDR(ht), HT_SIZE_EX(ht->nTableSize, HT_MIN_MASK), HT_USED_SIZE(ht), GC_FLAGS(ht) & IS_ARRAY_PERSISTENT));
@@ -1190,7 +1197,7 @@ static void ZEND_FASTCALL zend_hash_do_resize(HashTabl
 		pefree(old_data, GC_FLAGS(ht) & IS_ARRAY_PERSISTENT);
 		zend_hash_rehash(ht);
 	} else {
-		zend_error_noreturn(E_ERROR, "Possible integer overflow in memory allocation (%u * %zu + %zu)", ht->nTableSize * 2, sizeof(Bucket) + sizeof(uint32_t), sizeof(Bucket));
+		zend_mm_safe_error_ex("Possible integer overflow in memory allocation (%u * %zu + %zu)", ht->nTableSize * 2, sizeof(Bucket) + sizeof(uint32_t), sizeof(Bucket));
 	}
 }
 
