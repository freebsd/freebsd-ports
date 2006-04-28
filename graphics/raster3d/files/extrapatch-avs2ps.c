--- avs2ps.c.orig	Fri Apr 28 15:34:10 2006
+++ avs2ps.c	Fri Apr 28 15:35:09 2006
@@ -10,7 +10,7 @@
 #include	<math.h>
 #include	<string.h>
 #include	<stdlib.h>
-#include	<netinet/in.h>
+#include	"in.h"
 
 #ifdef WIN32
 #define random rand
