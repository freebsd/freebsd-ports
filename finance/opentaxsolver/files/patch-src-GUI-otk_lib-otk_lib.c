$FreeBSD$
--- src/GUI/otk_lib/otk_lib.c.orig	Fri Mar 31 21:42:34 2006
+++ src/GUI/otk_lib/otk_lib.c	Sat Apr  8 11:50:21 2006
@@ -38,6 +38,10 @@
 /* Set debug switch. 1=verbose.  0=quiet. */
 #define DEBUG if (0)
 
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#endif
+
 #include "otk_lib.h"
 
 int Otk_verbose=0;
