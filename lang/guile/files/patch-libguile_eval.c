--- libguile/eval.c	2008-07-09 14:44:29.000000000 +0800
+++ libguile/eval.c	2008-07-09 14:45:45.000000000 +0800
@@ -42,6 +42,8 @@
 #ifndef alloca
 # if HAVE_ALLOCA_H
 #  include <alloca.h>
+# elif defined __FreeBSD__
+#  include <stdlib.h>
 # elif defined __GNUC__
 #  define alloca __builtin_alloca
 # elif defined _AIX
