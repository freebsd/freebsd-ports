--- libguile/eval.c.orig	2010-12-13 17:24:39 UTC
+++ libguile/eval.c
@@ -40,6 +40,8 @@
 #ifndef alloca
 # if HAVE_ALLOCA_H
 #  include <alloca.h>
+# elif defined __FreeBSD__
+#  include <stdlib.h>
 # elif defined __GNUC__
 #  define alloca __builtin_alloca
 # elif defined _AIX
