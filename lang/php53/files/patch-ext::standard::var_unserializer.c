--- ext/standard/var_unserializer.c.orig	2004/12/03 16:02:48
+++ ext/standard/var_unserializer.c	2005/01/18 10:57:05
@@ -56,6 +56,30 @@ static inline void var_push(php_unserial
 	var_hash->data[var_hash->used_slots++] = *rval;
 }

+static inline void var_push_dtor(php_unserialize_data_t *var_hashx, zval **rval)
+{
+	var_entries *var_hash = var_hashx->first_dtor, *prev = NULL;
+
+	while (var_hash && var_hash->used_slots == VAR_ENTRIES_MAX) {
+		prev = var_hash;
+		var_hash = var_hash->next;
+	}
+
+	if (!var_hash) {
+		var_hash = emalloc(sizeof(var_entries));
+		var_hash->used_slots = 0;
+		var_hash->next = 0;
+
+		if (!var_hashx->first_dtor)
+			var_hashx->first_dtor = var_hash;
+		else
+			prev->next = var_hash;
+	}
+
+	(*rval)->refcount++;
+	var_hash->data[var_hash->used_slots++] = *rval;
+}
+
 PHPAPI void var_replace(php_unserialize_data_t *var_hashx, zval *ozval, zval **nzval)
 {
 	int i;
@@ -93,6 +117,7 @@ static int var_access(php_unserialize_da
 PHPAPI void var_destroy(php_unserialize_data_t *var_hashx)
 {
 	void *next;
+	int i;
 	var_entries *var_hash = var_hashx->first;

 	while (var_hash) {
@@ -100,6 +125,17 @@ PHPAPI void var_destroy(php_unserialize_
 		efree(var_hash);
 		var_hash = next;
 	}
+
+	var_hash = var_hashx->first_dtor;
+
+	while (var_hash) {
+		for (i = 0; i < var_hash->used_slots; i++) {
+			zval_ptr_dtor(&var_hash->data[i]);
+		}
+		next = var_hash->next;
+		efree(var_hash);
+		var_hash = next;
+	}
 }

 /* }}} */
@@ -177,7 +213,7 @@ static inline size_t parse_uiv(const uns
 static inline int process_nested_data(UNSERIALIZE_PARAMETER, HashTable *ht, int elements)
 {
 	while (elements-- > 0) {
-		zval *key, *data, *old_data;
+		zval *key, *data, **old_data;

 		ALLOC_INIT_ZVAL(key);

@@ -205,14 +241,14 @@ static inline int process_nested_data(UN

 		switch (Z_TYPE_P(key)) {
 			case IS_LONG:
-				if (zend_hash_index_find(ht, Z_LVAL_P(key), (void **)&old_data)) {
-					var_replace(var_hash, old_data, rval);
+				if (zend_hash_index_find(ht, Z_LVAL_P(key), (void **)&old_data)==SUCCESS) {
+					var_push_dtor(var_hash, old_data);
 				}
 				zend_hash_index_update(ht, Z_LVAL_P(key), &data, sizeof(data), NULL);
 				break;
 			case IS_STRING:
-				if (zend_hash_find(ht, Z_STRVAL_P(key), Z_STRLEN_P(key) + 1, (void **)&old_data)) {
-					var_replace(var_hash, old_data, rval);
+				if (zend_hash_find(ht, Z_STRVAL_P(key), Z_STRLEN_P(key) + 1, (void **)&old_data)==SUCCESS) {
+					var_push_dtor(var_hash, old_data);
 				}
 				zend_hash_update(ht, Z_STRVAL_P(key), Z_STRLEN_P(key) + 1, &data, sizeof(data), NULL);
 				break;
