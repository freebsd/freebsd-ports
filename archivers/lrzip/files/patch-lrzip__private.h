--- lrzip_private.h.orig	2015-03-10 09:25:42 UTC
+++ lrzip_private.h
@@ -47,7 +47,7 @@
 #ifdef HAVE_ALLOCA_H
 # include <alloca.h>
 #elif defined __GNUC__
-# define alloca __builtin_alloca
+# include <stdlib.h>
 #elif defined _AIX
 # define alloca __alloca
 #elif defined _MSC_VER
