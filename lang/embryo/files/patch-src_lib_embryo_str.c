--- src/lib/embryo_str.c.orig	2010-12-11 21:54:43.000000000 -0800
+++ src/lib/embryo_str.c	2010-12-11 21:55:03.000000000 -0800
@@ -9,7 +9,7 @@
 
 #ifdef HAVE_ALLOCA_H
 # include <alloca.h>
-#elif defined __GNUC__
+#elif defined __GNUC__ && !defined __FreeBSD__
 # define alloca __builtin_alloca
 #elif defined _AIX
 # define alloca __alloca
