--- src/util.h.orig	2024-01-31 20:08:46 UTC
+++ src/util.h
@@ -8,7 +8,9 @@
 #ifndef EFIVAR_UTIL_H
 #define EFIVAR_UTIL_H 1
 
-#include <alloca.h>
+#if defined(__linux__)
+#  include <alloca.h>
+#endif
 #include <ctype.h>
 #include <endian.h>
 #include <err.h>
