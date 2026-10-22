--- Zend/zend_vm_execute.h.orig	2026-10-21 15:33:56 UTC
+++ Zend/zend_vm_execute.h
@@ -6348,6 +6348,9 @@ static ZEND_VM_COLD ZEND_OPCODE_HANDLER_RET ZEND_FASTC
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -6355,6 +6358,9 @@ static ZEND_VM_COLD ZEND_OPCODE_HANDLER_RET ZEND_FASTC
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -8225,7 +8231,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -8234,6 +8240,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -8641,6 +8650,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -8648,6 +8660,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -10613,7 +10628,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -10622,6 +10637,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -11029,6 +11047,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -11036,6 +11057,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -14644,7 +14668,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -14653,6 +14677,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -15374,6 +15401,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -15381,6 +15411,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -16067,7 +16100,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -16076,6 +16109,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -16797,6 +16833,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -16804,6 +16843,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -17744,7 +17786,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -17753,6 +17795,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -18112,6 +18157,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -18119,6 +18167,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -39226,7 +39277,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -39235,6 +39286,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -41677,6 +41731,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -41684,6 +41741,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -42951,7 +43011,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -42960,6 +43020,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -45331,6 +45394,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -45338,6 +45404,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -48150,7 +48219,7 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 		    size_t len = ZSTR_LEN(op1_str);
 
 			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
-				zend_error_noreturn(E_ERROR, "Integer overflow in memory allocation");
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
 			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -48159,6 +48228,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_CONC
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
@@ -50629,6 +50701,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 		    !ZSTR_IS_INTERNED(op1_str) && GC_REFCOUNT(op1_str) == 1) {
 		    size_t len = ZSTR_LEN(op1_str);
 
+			if (UNEXPECTED(len > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_extend(op1_str, len + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str) + len, ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
 			ZVAL_NEW_STR(EX_VAR(opline->result.var), str);
@@ -50636,6 +50711,9 @@ static ZEND_OPCODE_HANDLER_RET ZEND_FASTCALL ZEND_FAST
 				zend_string_release_ex(op2_str, 0);
 			}
 		} else {
+			if (UNEXPECTED(ZSTR_LEN(op1_str) > ZSTR_MAX_LEN - ZSTR_LEN(op2_str))) {
+				zend_mm_safe_error_ex("Integer overflow in memory allocation");
+			}
 			str = zend_string_alloc(ZSTR_LEN(op1_str) + ZSTR_LEN(op2_str), 0);
 			memcpy(ZSTR_VAL(str), ZSTR_VAL(op1_str), ZSTR_LEN(op1_str));
 			memcpy(ZSTR_VAL(str) + ZSTR_LEN(op1_str), ZSTR_VAL(op2_str), ZSTR_LEN(op2_str)+1);
