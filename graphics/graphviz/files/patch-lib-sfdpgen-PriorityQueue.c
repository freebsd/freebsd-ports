--- lib/sfdpgen/PriorityQueue.c.orig	2020-04-08 07:51:57 UTC
+++ lib/sfdpgen/PriorityQueue.c
@@ -11,7 +11,7 @@
  * Contributors: See CVS logs. Details at http://www.graphviz.org/
  *************************************************************************/
 
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "LinkedList.h"
 #include "PriorityQueue.h"
