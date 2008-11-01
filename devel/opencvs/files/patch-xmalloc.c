--- xmalloc.c	22 Feb 2007 06:42:10 -0000	1.8
+++ xmalloc.c	17 Oct 2008 08:51:46 -0000
@@ -13,6 +13,8 @@
  * called by a name other than "ssh" or "Secure Shell".
  */
 
+#include <sys/types.h>
+
 #include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>

