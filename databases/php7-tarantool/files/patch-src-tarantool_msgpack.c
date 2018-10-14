--- src/tarantool_msgpack.c.orig	2018-04-18 13:33:56 UTC
+++ src/tarantool_msgpack.c
@@ -123,15 +123,30 @@ void php_mp_pack_array_recursively(smart
 	for (; key_index < n; ++key_index) {
 		data = zend_hash_index_find(ht, key_index);
 		if (!data || data == val || (Z_TYPE_P(data) == IS_ARRAY &&
+#if PHP_VERSION_ID >= 70300
+					     !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE) &&
+					     GC_IS_RECURSIVE(Z_ARRVAL_P(data)))) {
+#else
 					     ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)) &&
 					     Z_ARRVAL_P(data)->u.v.nApplyCount > 1)) {
+#endif
 			php_mp_pack_nil(str);
 		} else {
+#if PHP_VERSION_ID >= 70300
+			if (Z_TYPE_P(data) == IS_ARRAY && !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE))
+				GC_PROTECT_RECURSION(Z_ARRVAL_P(data));
+#else
 			if (Z_TYPE_P(data) == IS_ARRAY && ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)))
 				Z_ARRVAL_P(data)->u.v.nApplyCount++;
+#endif
 			php_mp_pack(str, data);
+#if PHP_VERSION_ID >= 70300
+			if (Z_TYPE_P(data) == IS_ARRAY && !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE))
+				GC_UNPROTECT_RECURSION(Z_ARRVAL_P(data));
+#else
 			if (Z_TYPE_P(data) == IS_ARRAY && ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)))
 				Z_ARRVAL_P(data)->u.v.nApplyCount--;
+#endif
 		}
 	}
 }
@@ -166,15 +181,30 @@ void php_mp_pack_hash_recursively(smart_
 		}
 		data = zend_hash_get_current_data_ex(ht, &pos);
 		if (!data || data == val || (Z_TYPE_P(data) == IS_ARRAY &&
+#if PHP_VERSION_ID >= 70300
+					    !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE) &&
+					    GC_IS_RECURSIVE(Z_ARRVAL_P(data)))) {
+#else
 					    ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)) &&
 					    Z_ARRVAL_P(data)->u.v.nApplyCount > 1)) {
+#endif
 			php_mp_pack_nil(str);
 		} else {
+#if PHP_VERSION_ID >= 70300
+			if (Z_TYPE_P(data) == IS_ARRAY && !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE))
+				GC_PROTECT_RECURSION(Z_ARRVAL_P(data));
+#else
 			if (Z_TYPE_P(data) == IS_ARRAY && ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)))
 				Z_ARRVAL_P(data)->u.v.nApplyCount++;
+#endif
 			php_mp_pack(str, data);
+#if PHP_VERSION_ID >= 70300
+			if (Z_TYPE_P(data) == IS_ARRAY && !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE))
+				GC_UNPROTECT_RECURSION(Z_ARRVAL_P(data));
+#else
 			if (Z_TYPE_P(data) == IS_ARRAY && ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)))
 				Z_ARRVAL_P(data)->u.v.nApplyCount--;
+#endif
 		}
 	}
 }
@@ -408,14 +438,28 @@ size_t php_mp_sizeof_array_recursively(z
 	for (; key_index < n; ++key_index) {
 		data = zend_hash_index_find(ht, key_index);
 		if (!data || data == val ||
+#if PHP_VERSION_ID >= 70300
+				(Z_TYPE_P(data) == IS_ARRAY && !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE) && GC_IS_RECURSIVE(Z_ARRVAL_P(data)))) {
+#else
 				(Z_TYPE_P(data) == IS_ARRAY && ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)) && Z_ARRVAL_P(data)->u.v.nApplyCount > 1)) {
+#endif
 			needed += php_mp_sizeof_nil();
 		} else {
+#if PHP_VERSION_ID >= 70300
+			if (Z_TYPE_P(data) == IS_ARRAY && !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE))
+				GC_PROTECT_RECURSION(Z_ARRVAL_P(data));
+#else
 			if (Z_TYPE_P(data) == IS_ARRAY && ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)))
 				Z_ARRVAL_P(data)->u.v.nApplyCount++;
+#endif
 			needed += php_mp_sizeof(data);
+#if PHP_VERSION_ID >= 70300
+			if (Z_TYPE_P(data) == IS_ARRAY && !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE))
+				GC_UNPROTECT_RECURSION(Z_ARRVAL_P(data));
+#else
 			if (Z_TYPE_P(data) == IS_ARRAY && ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)))
 				Z_ARRVAL_P(data)->u.v.nApplyCount--;
+#endif
 		}
 	}
 	return needed;
@@ -452,14 +496,28 @@ size_t php_mp_sizeof_hash_recursively(zv
 		}
 		data = zend_hash_get_current_data_ex(ht, &pos);
 		if (!data || data == val ||
+#if PHP_VERSION_ID >= 70300
+				(Z_TYPE_P(data) == IS_ARRAY && !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE) && GC_IS_RECURSIVE(Z_ARRVAL_P(data)))) {
+#else
 				(Z_TYPE_P(data) == IS_ARRAY && ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)) && Z_ARRVAL_P(data)->u.v.nApplyCount > 1)) {
+#endif
 			needed += php_mp_sizeof_nil();
 		} else {
+#if PHP_VERSION_ID >= 70300
+			if (Z_TYPE_P(data) == IS_ARRAY && !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE))
+				GC_PROTECT_RECURSION(Z_ARRVAL_P(data));
+#else
 			if (Z_TYPE_P(data) == IS_ARRAY && ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)))
 				Z_ARRVAL_P(data)->u.v.nApplyCount++;
+#endif
 			needed += php_mp_sizeof(data);
+#if PHP_VERSION_ID >= 70300
+			if (Z_TYPE_P(data) == IS_ARRAY && !(GC_FLAGS(Z_ARRVAL_P(data)) & GC_IMMUTABLE))
+				GC_UNPROTECT_RECURSION(Z_ARRVAL_P(data));
+#else
 			if (Z_TYPE_P(data) == IS_ARRAY && ZEND_HASH_APPLY_PROTECTION(Z_ARRVAL_P(data)))
 				Z_ARRVAL_P(data)->u.v.nApplyCount--;
+#endif
 		}
 	}
 	return needed;
