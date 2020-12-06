--- src/postgres/include/port/atomics.h.orig	2020-12-06 21:56:04 UTC
+++ src/postgres/include/port/atomics.h
@@ -71,7 +71,7 @@
 #elif defined(__ia64__) || defined(__ia64)
 #include "port/atomics/arch-ia64.h"
 #elif defined(__ppc__) || defined(__powerpc__) || defined(__ppc64__) || defined(__powerpc64__)
-#include "port/atomics/arch-ppc.h"
+#include <postgresql/server/port/atomics/arch-ppc.h>
 #elif defined(__hppa) || defined(__hppa__)
 #include "port/atomics/arch-hppa.h"
 #endif
