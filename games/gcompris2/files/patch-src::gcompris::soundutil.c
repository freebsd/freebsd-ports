
$FreeBSD$

--- src/gcompris/soundutil.c	2002/03/20 10:35:57	1.1
+++ src/gcompris/soundutil.c	2002/03/20 10:36:14
@@ -19,6 +19,7 @@
  *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#include <signal.h>
 #include "gcompris.h"
 
 static GList *pending_queue = NULL;
