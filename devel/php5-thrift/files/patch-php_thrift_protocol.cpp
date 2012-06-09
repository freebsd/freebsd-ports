--- ./php_thrift_protocol.cpp.orig	2011-11-26 23:00:43.000000000 +0400
+++ ./php_thrift_protocol.cpp	2012-06-06 09:40:16.000000000 +0400
@@ -57,6 +57,10 @@
 #error Unknown __BYTE_ORDER
 #endif
 
+#ifndef Z_ADDREF_P
+#define Z_ADDREF_P ZVAL_ADDREF
+#endif
+
 enum TType {
   T_STOP       = 0,
   T_VOID       = 1,
@@ -92,7 +96,7 @@
 #include "zend_exceptions.h"
 #include "php_thrift_protocol.h"
 
-static function_entry thrift_protocol_functions[] = {
+static zend_function_entry thrift_protocol_functions[] = {
   PHP_FE(thrift_protocol_write_binary, NULL)
   PHP_FE(thrift_protocol_read_binary, NULL)
   {NULL, NULL, NULL}
@@ -764,6 +768,7 @@
 }
 
 void binary_serialize(int8_t thrift_typeID, PHPOutputTransport& transport, zval** value, HashTable* fieldspec) {
+  Z_ADDREF_P(*value);
   // At this point the typeID (and field num, if applicable) should've already been written to the output so all we need to do is write the payload.
   switch (thrift_typeID) {
     case T_STOP:
@@ -781,29 +786,51 @@
       binary_serialize_spec(*value, transport, Z_ARRVAL_P(spec));
     } return;
     case T_BOOL:
-      if (Z_TYPE_PP(value) != IS_BOOL) convert_to_boolean(*value);
+      if (Z_TYPE_PP(value) != IS_BOOL) {
+        SEPARATE_ZVAL(value);
+        convert_to_boolean(*value);
+      }
       transport.writeI8(Z_BVAL_PP(value) ? 1 : 0);
+      zval_ptr_dtor(value);
       return;
     case T_BYTE:
-      if (Z_TYPE_PP(value) != IS_LONG) convert_to_long(*value);
+      if (Z_TYPE_PP(value) != IS_LONG) {
+        SEPARATE_ZVAL(value);
+        convert_to_long(*value);
+      }
       transport.writeI8(Z_LVAL_PP(value));
+      zval_ptr_dtor(value);
       return;
     case T_I16:
-      if (Z_TYPE_PP(value) != IS_LONG) convert_to_long(*value);
+      if (Z_TYPE_PP(value) != IS_LONG) {
+        SEPARATE_ZVAL(value);
+        convert_to_long(*value);
+      }
       transport.writeI16(Z_LVAL_PP(value));
+      zval_ptr_dtor(value);
       return;
     case T_I32:
-      if (Z_TYPE_PP(value) != IS_LONG) convert_to_long(*value);
+      if (Z_TYPE_PP(value) != IS_LONG) {
+        SEPARATE_ZVAL(value);
+        convert_to_long(*value);
+      }
       transport.writeI32(Z_LVAL_PP(value));
+      zval_ptr_dtor(value);
       return;
     case T_I64:
     case T_U64: {
       int64_t l_data;
 #if defined(_LP64) || defined(_WIN64)
-      if (Z_TYPE_PP(value) != IS_LONG) convert_to_long(*value);
+      if (Z_TYPE_PP(value) != IS_LONG) {
+        SEPARATE_ZVAL(value);
+        convert_to_long(*value);
+      }
       l_data = Z_LVAL_PP(value);
 #else
-      if (Z_TYPE_PP(value) != IS_DOUBLE) convert_to_double(*value);
+      if (Z_TYPE_PP(value) != IS_DOUBLE) {
+        SEPARATE_ZVAL(value);
+        convert_to_double(*value);
+      }
       l_data = (int64_t)Z_DVAL_PP(value);
 #endif
       transport.writeI64(l_data);
@@ -813,20 +840,32 @@
         int64_t c;
         double d;
       } a;
-      if (Z_TYPE_PP(value) != IS_DOUBLE) convert_to_double(*value);
+      if (Z_TYPE_PP(value) != IS_DOUBLE) {
+        SEPARATE_ZVAL(value);
+        convert_to_double(*value);
+      }
       a.d = Z_DVAL_PP(value);
       transport.writeI64(a.c);
+      zval_ptr_dtor(value);
     } return;
     //case T_UTF7:
     case T_UTF8:
     case T_UTF16:
     case T_STRING:
-      if (Z_TYPE_PP(value) != IS_STRING) convert_to_string(*value);
+      if (Z_TYPE_PP(value) != IS_STRING) {
+        SEPARATE_ZVAL(value);
+        convert_to_string(*value);
+      }
       transport.writeString(Z_STRVAL_PP(value), Z_STRLEN_PP(value));
+      zval_ptr_dtor(value);
       return;
     case T_MAP: {
-      if (Z_TYPE_PP(value) != IS_ARRAY) convert_to_array(*value);
       if (Z_TYPE_PP(value) != IS_ARRAY) {
+        SEPARATE_ZVAL(value);
+        convert_to_array(*value);
+      }
+      if (Z_TYPE_PP(value) != IS_ARRAY) {
+        zval_ptr_dtor(value);
         throw_tprotocolexception("Attempt to send an incompatible type as an array (T_MAP)", INVALID_DATA);
       }
       HashTable* ht = Z_ARRVAL_PP(value);
@@ -850,10 +889,15 @@
         binary_serialize_hashtable_key(keytype, transport, ht, key_ptr);
         binary_serialize(valtype, transport, val_ptr, valspec);
       }
+      zval_ptr_dtor(value);
     } return;
     case T_LIST: {
-      if (Z_TYPE_PP(value) != IS_ARRAY) convert_to_array(*value);
       if (Z_TYPE_PP(value) != IS_ARRAY) {
+        SEPARATE_ZVAL(value);
+        convert_to_array(*value);
+      }
+      if (Z_TYPE_PP(value) != IS_ARRAY) {
+        zval_ptr_dtor(value);
         throw_tprotocolexception("Attempt to send an incompatible type as an array (T_LIST)", INVALID_DATA);
       }
       HashTable* ht = Z_ARRVAL_PP(value);
@@ -872,10 +916,15 @@
       for (zend_hash_internal_pointer_reset_ex(ht, &key_ptr); zend_hash_get_current_data_ex(ht, (void**)&val_ptr, &key_ptr) == SUCCESS; zend_hash_move_forward_ex(ht, &key_ptr)) {
         binary_serialize(valtype, transport, val_ptr, valspec);
       }
+      zval_ptr_dtor(value);
     } return;
     case T_SET: {
-      if (Z_TYPE_PP(value) != IS_ARRAY) convert_to_array(*value);
       if (Z_TYPE_PP(value) != IS_ARRAY) {
+        SEPARATE_ZVAL(value);
+        convert_to_array(*value);
+      }
+      if (Z_TYPE_PP(value) != IS_ARRAY) {
+        zval_ptr_dtor(value);
         throw_tprotocolexception("Attempt to send an incompatible type as an array (T_SET)", INVALID_DATA);
       }
       HashTable* ht = Z_ARRVAL_PP(value);
@@ -891,8 +940,11 @@
       for (zend_hash_internal_pointer_reset_ex(ht, &key_ptr); zend_hash_get_current_data_ex(ht, (void**)&val_ptr, &key_ptr) == SUCCESS; zend_hash_move_forward_ex(ht, &key_ptr)) {
         binary_serialize_hashtable_key(keytype, transport, ht, key_ptr);
       }
+      zval_ptr_dtor(value);
     } return;
   };
+
+  zval_ptr_dtor(value);
   char errbuf[128];
   sprintf(errbuf, "Unknown thrift typeID %d", thrift_typeID);
   throw_tprotocolexception(errbuf, INVALID_DATA);
