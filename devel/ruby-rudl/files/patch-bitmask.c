--- bitmask.c.orig	Sat Sep  7 19:51:41 2002
+++ bitmask.c	Mon Apr 19 04:20:51 2004
@@ -26,7 +26,7 @@
  *Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
  */
 
-#include <malloc.h>
+#include <stdlib.h>
 #include "bitmask.h"
 
 #define MIN(a,b) ((a) < (b) ? (a) : (b))
