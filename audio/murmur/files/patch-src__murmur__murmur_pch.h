--- src/murmur/murmur_pch.h.orig	2009-08-04 21:37:28.000000000 +0900
+++ src/murmur/murmur_pch.h		2009-08-04 21:38:17.000000000 +0900
@@ -74,7 +74,6 @@
 #define ALLOCA(x) _alloca(x)
 #define snprintf ::_snprintf
 #else
-#include <alloca.h>
 #define ALLOCA(x) alloca(x)
 #endif
 #if defined (Q_CC_GNU) || (defined (Q_CC_INTEL) && !defined (Q_OS_WIN))
