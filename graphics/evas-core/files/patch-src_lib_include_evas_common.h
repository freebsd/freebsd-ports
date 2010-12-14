--- src/lib/include/evas_common.h.orig	2010-12-06 01:26:44.000000000 -0800
+++ src/lib/include/evas_common.h	2010-12-06 01:27:46.000000000 -0800
@@ -192,7 +192,7 @@
 
 #ifdef HAVE_ALLOCA_H
 # include <alloca.h>
-#elif defined __GNUC__
+#elif defined __GNUC__ && !defined __FreeBSD__
 # define alloca __builtin_alloca
 #elif defined _AIX
 # define alloca __alloca
