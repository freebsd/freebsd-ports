--- def.h.orig	2023-10-22 13:42:02 UTC
+++ def.h
@@ -10,6 +10,7 @@
  * per-terminal definitions are in special header files.
  */
 
+#include    <unistd.h>
 #include	"chrdef.h"
 
 typedef int	(*PF)(int, int);	/* generally useful type */
