--- gdb/config/sparc/tm-fbsd.h.orig	Fri Mar  1 18:35:24 2002
+++ gdb/config/sparc/tm-fbsd.h	Thu Oct 17 06:01:10 2002
@@ -22,13 +22,7 @@
 #define TM_FBSD_H
 
 #define SVR4_SHARED_LIBS
+#include "sparc/tm-sp64.h"		/* sets GDB_MULTI_ARCH */
 #include "solib.h"			/* Support for shared libraries. */
-#include "sparc/tm-sp64.h"
-
-/* Number of traps that happen between exec'ing the shell to run an
-   inferior, and when we finally get to the inferior code.  The
-   default is right for FreeBSD.  */
-
-#undef START_INFERIOR_TRAPS_EXPECTED
 
 #endif /* TM_FBSD_H */
