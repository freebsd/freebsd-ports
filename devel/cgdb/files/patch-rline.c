--- various/rline/src/rline.c.orig	2011-02-03 10:54:48.000000000 +0100
+++ various/rline/src/rline.c	2011-02-03 10:56:01.000000000 +0100
@@ -42,6 +42,8 @@
 
 #endif /* HAVE_LIBREADLINE */
 
+#include "various/util/include/sys_util.h"
+
 /* }}}*/
 
 struct rline
