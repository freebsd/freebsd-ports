--- libiberty/getpwd.c.orig	Tue May 24 13:48:25 2005
+++ libiberty/getpwd.c	Sat Jan 27 17:43:11 2007
@@ -39,6 +39,10 @@
 #include <limits.h>
 #endif
 
+#ifndef PATH_MAX
+#define PATH_MAX 512
+#endif
+
 #include "libiberty.h"
 
 /* Virtually every UN*X system now in common use (except for pre-4.3-tahoe
