--- newlib/libc/stdlib/strtoull_r.c.orig	2020-10-04 20:42:46 UTC
+++ newlib/libc/stdlib/strtoull_r.c
@@ -43,6 +43,7 @@
 #ifdef __GNUC__
 
 #define _GNU_SOURCE
+#define __LONG_LONG_SUPPORTED
 #include <_ansi.h>
 #include <limits.h>
 #include <ctype.h>
@@ -88,8 +89,8 @@ _DEFUN (_strtoull_r, (rptr, nptr, endptr, base),
 	}
 	if (base == 0)
 		base = c == '0' ? 8 : 10;
-	cutoff = (unsigned long long)ULONG_LONG_MAX / (unsigned long long)base;
-	cutlim = (unsigned long long)ULONG_LONG_MAX % (unsigned long long)base;
+	cutoff = (unsigned long long)ULLONG_MAX / (unsigned long long)base;
+	cutlim = (unsigned long long)ULLONG_MAX % (unsigned long long)base;
 	for (acc = 0, any = 0;; c = *s++) {
 		if (isdigit(c))
 			c -= '0';
@@ -108,7 +109,7 @@ _DEFUN (_strtoull_r, (rptr, nptr, endptr, base),
 		}
 	}
 	if (any < 0) {
-		acc = ULONG_LONG_MAX;
+		acc = ULLONG_MAX;
 		rptr->_errno = ERANGE;
 	} else if (neg)
 		acc = -acc;
