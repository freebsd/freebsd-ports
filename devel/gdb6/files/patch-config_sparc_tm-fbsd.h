--- gdb/config/sparc/tm-fbsd.h.orig	Sat Jan 24 20:06:31 2004
+++ gdb/config/sparc/tm-fbsd.h	Sat Jan 24 20:07:02 2004
@@ -24,4 +24,9 @@
 
 #define GDB_MULTI_ARCH GDB_MULTI_ARCH_TM
 
+#if 0
+#define SVR4_SHARED_LIBS
+#include "sparc/tm-sp64.h"		/* sets GDB_MULTI_ARCH */
+#endif
+
 #endif /* tm-fbsd.h */
