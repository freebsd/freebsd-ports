--- xmalloc.c.orig	2009-06-07 10:39:13.000000000 +0200
+++ xmalloc.c	2010-06-08 20:18:08.000000000 +0200
@@ -13,6 +13,8 @@
  * called by a name other than "ssh" or "Secure Shell".
  */
 
+#include <sys/types.h>
+
 #include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
