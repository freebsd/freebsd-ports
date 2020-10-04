--- newlib/libc/stdlib/strtoll_r.c.orig	2020-10-04 20:42:31 UTC
+++ newlib/libc/stdlib/strtoll_r.c
@@ -42,6 +42,7 @@
 #ifdef __GNUC__
 
 #define _GNU_SOURCE
+#define __LONG_LONG_SUPPORTED
 #include <_ansi.h>
 #include <limits.h>
 #include <ctype.h>
@@ -107,7 +108,7 @@ _DEFUN (_strtoll_r, (rptr, nptr, endptr, base),
 	 * Set any if any `digits' consumed; make it negative to indicate
 	 * overflow.
 	 */
-	cutoff = neg ? -(unsigned long long)LONG_LONG_MIN : LONG_LONG_MAX;
+	cutoff = neg ? -(unsigned long long)LLONG_MIN : LLONG_MAX;
 	cutlim = cutoff % (unsigned long long)base;
 	cutoff /= (unsigned long long)base;
 	for (acc = 0, any = 0;; c = *s++) {
@@ -128,7 +129,7 @@ _DEFUN (_strtoll_r, (rptr, nptr, endptr, base),
 		}
 	}
 	if (any < 0) {
-		acc = neg ? LONG_LONG_MIN : LONG_LONG_MAX;
+		acc = neg ? LLONG_MIN : LLONG_MAX;
 		rptr->_errno = ERANGE;
 	} else if (neg)
 		acc = -acc;
