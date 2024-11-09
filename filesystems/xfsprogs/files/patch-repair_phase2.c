--- repair/phase2.c.orig	2015-07-28 23:02:16 UTC
+++ repair/phase2.c
@@ -16,6 +16,7 @@
  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  */
 
+#include <inttypes.h>
 #include <xfs/libxlog.h>
 #include "avl.h"
 #include "globals.h"
