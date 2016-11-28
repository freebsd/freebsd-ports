--- stress-ng.h.orig	2016-11-28 10:45:15.430051000 +0100
+++ stress-ng.h	2016-11-28 10:45:25.621013000 +0100
@@ -27,6 +27,7 @@
 #define __STRESS_NG_H__
 
 #define _GNU_SOURCE
+#define _DECLARE_C99_LDBL_MATH 1
 
 #include <stdarg.h>
 #include <stdint.h>
