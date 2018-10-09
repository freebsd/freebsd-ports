--- swoole_serialize.c.orig	2018-05-14 10:43:31 UTC
+++ swoole_serialize.c
@@ -658,11 +658,17 @@ static void* swoole_unserialize_arr(void
     ht->nNumUsed = nNumOfElements;
     ht->nNumOfElements = nNumOfElements;
     ht->nNextFreeElement = 0;
+#ifdef HASH_FLAG_APPLY_PROTECTION
     ht->u.flags = HASH_FLAG_APPLY_PROTECTION;
+#endif
     ht->nTableMask = -(ht->nTableSize);
     ht->pDestructor = ZVAL_PTR_DTOR;
 
+#if PHP_VERSION_ID < 70300
     GC_REFCOUNT(ht) = 1;
+#else
+    GC_SET_REFCOUNT(ht, 1);
+#endif
     GC_TYPE_INFO(ht) = IS_ARRAY;
     // if (ht->nNumUsed)
     //{
@@ -985,8 +991,9 @@ try_again:
             {
                 zend_array *ht = Z_ARRVAL_P(data);
 
-                if (ZEND_HASH_GET_APPLY_COUNT(ht) > 1)
+                if (GC_IS_RECURSIVE(ht))
                 {
+                    ((SBucketType*) (buffer->buffer + p))->data_type = IS_NULL; //reset type null
                     php_error_docref(NULL TSRMLS_CC, E_NOTICE, "you array have cycle ref");
                 }
                 else
@@ -994,9 +1001,9 @@ try_again:
                     seria_array_type(ht, buffer, p, buffer->offset);
                     if (ZEND_HASH_APPLY_PROTECTION(ht))
                     {
-                        ZEND_HASH_INC_APPLY_COUNT(ht);
+                        GC_PROTECT_RECURSION(ht);
                         swoole_serialize_arr(buffer, ht);
-                        ZEND_HASH_DEC_APPLY_COUNT(ht);
+                        GC_UNPROTECT_RECURSION(ht);
                     }
                     else
                     {
@@ -1022,9 +1029,9 @@ try_again:
 
                 if (ZEND_HASH_APPLY_PROTECTION(Z_OBJPROP_P(data)))
                 {
-                    ZEND_HASH_INC_APPLY_COUNT(Z_OBJPROP_P(data));
+                    GC_PROTECT_RECURSION(Z_OBJPROP_P(data));
                     swoole_serialize_object(buffer, data, p);
-                    ZEND_HASH_DEC_APPLY_COUNT(Z_OBJPROP_P(data));
+                    GC_UNPROTECT_RECURSION(Z_OBJPROP_P(data));
                 }
                 else
                 {
@@ -1405,7 +1412,11 @@ PHPAPI zend_string* php_swoole_serialize
     z_str->val[str.offset] = '\0';
     z_str->len = str.offset - _STR_HEADER_SIZE;
     z_str->h = 0;
+#if PHP_VERSION_ID < 70300
     GC_REFCOUNT(z_str) = 1;
+#else
+    GC_SET_REFCOUNT(z_str, 1);
+#endif
     GC_TYPE_INFO(z_str) = IS_STRING_EX;
 
     return z_str;
