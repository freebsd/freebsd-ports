--- Zend/zend_vm_def.h.orig	2026-10-21 15:33:56 UTC
+++ Zend/zend_vm_def.h
@@ -408,7 +408,7 @@ ZEND_VM_HANDLER(8, ZEND_CONCAT, CONST|TMPVAR|CV, CONST
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -417,6 +417,9 @@ ZEND_VM_HANDLER(8, ZEND_CONCAT, CONST|TMPVAR|CV, CONST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -3157,6 +3160,9 @@ ZEND_VM_COLD_CONSTCONST_HANDLER(53, ZEND_FAST_CONCAT, 
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -3164,6 +3170,9 @@ ZEND_VM_COLD_CONSTCONST_HANDLER(53, ZEND_FAST_CONCAT, 
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
