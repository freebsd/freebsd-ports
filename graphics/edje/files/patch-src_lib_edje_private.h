--- src/lib/edje_private.h.orig	2010-12-11 00:51:59.000000000 -0800
+++ src/lib/edje_private.h	2010-12-11 00:52:57.000000000 -0800
@@ -11,6 +11,8 @@
 
 #ifdef HAVE_ALLOCA_H
 # include <alloca.h>
+#elif defined __FreeBSD__
+# include <stdlib.h>
 #elif defined __GNUC__
 # define alloca __builtin_alloca
 #elif defined _AIX
