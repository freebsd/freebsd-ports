--- ajax/ajjava.c.orig	Thu May  2 22:06:08 2002
+++ ajax/ajjava.c	Sun May 26 09:14:20 2002
@@ -75,7 +75,7 @@
 #endif
 
 #ifndef __ppc__
-#include <crypt.h>
+#include <unistd.h>
 #endif
 
 
