--- src/i386/icsprite.c.orig	Sat Apr 21 00:54:32 2007
+++ src/i386/icsprite.c	Thu May  3 15:30:34 2007
@@ -16,6 +16,8 @@
  */
 
 
+#include <machine/param.h>
+#include <sys/mman.h>
 #include <stdio.h>
 #include <string.h>
 
