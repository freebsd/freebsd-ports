--- src/rc4.c.orig	Sun Dec 24 01:17:00 2006
+++ src/rc4.c	Sun Dec 24 01:17:25 2006
@@ -21,6 +21,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 /*
  * Transparent rc4 implementation
