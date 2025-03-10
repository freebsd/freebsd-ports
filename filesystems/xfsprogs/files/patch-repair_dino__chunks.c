--- repair/dino_chunks.c.orig	2015-07-24 04:28:04 UTC
+++ repair/dino_chunks.c
@@ -16,6 +16,7 @@
  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  */
 
+#include <inttypes.h>
 #include <libxfs.h>
 #include "avl.h"
 #include "globals.h"
