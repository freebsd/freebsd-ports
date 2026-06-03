--- src/dp.h.orig	2024-01-31 20:08:46 UTC
+++ src/dp.h
@@ -6,7 +6,9 @@
 #ifndef _EFIVAR_INTERNAL_DP_H
 #define _EFIVAR_INTERNAL_DP_H
 
-#include <alloca.h>
+#if defined(__linux__)
+#  include <alloca.h>
+#endif
 #include <stdarg.h>
 #include <stdio.h>
 #include <stdlib.h>
