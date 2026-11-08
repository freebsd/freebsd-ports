--- Zend/zend_strtod.c.orig	2026-10-21 15:33:56 UTC
+++ Zend/zend_strtod.c
@@ -603,7 +603,7 @@ Balloc
 		rv = (Bigint *)MALLOC(sizeof(Bigint) + (x-1)*sizeof(ULong));
 		if (!rv) {
 			FREE_DTOA_LOCK(0);
-			zend_error_noreturn(E_ERROR, "Balloc() failed to allocate memory");
+			zend_mm_safe_error_ex("Balloc() failed to allocate memory");
 		}
 #else
 		len = (sizeof(Bigint) + (x-1)*sizeof(ULong) + sizeof(double) - 1)
@@ -616,7 +616,7 @@ Balloc
 			rv = (Bigint*)MALLOC(len*sizeof(double));
 			if (!rv) {
 				FREE_DTOA_LOCK(0);
-				zend_error_noreturn(E_ERROR, "Balloc() failed to allocate memory");
+				zend_mm_safe_error_ex("Balloc() failed to allocate memory");
 			}
 #endif
 		rv->k = k;
