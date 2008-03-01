--- libguile/eval.c	2008-02-23 18:14:28.083264040 -0600
+++ libguile/eval.c	2008-02-23 18:20:55.081183329 -0600
@@ -40,6 +40,8 @@
 /* This blob per the Autoconf manual (under "Particular Functions"). */
 #if HAVE_ALLOCA_H
 # include <alloca.h>
+#elif defined __FreeBSD__
+# include <stdlib.h>
 #elif defined __GNUC__
 # define alloca __builtin_alloca
 #elif defined _AIX
