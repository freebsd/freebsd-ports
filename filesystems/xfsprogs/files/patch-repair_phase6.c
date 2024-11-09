--- repair/phase6.c.orig	2015-07-24 04:28:04 UTC
+++ repair/phase6.c
@@ -16,6 +16,7 @@
  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  */
 
+#include <inttypes.h>
 #include <libxfs.h>
 #include "threads.h"
 #include "prefetch.h"
@@ -49,7 +50,7 @@ typedef struct dotdot_update {
 	int			ino_offset;
 } dotdot_update_t;
 
-static LIST_HEAD(dotdot_update_list);
+static XFS_LIST_HEAD(dotdot_update_list);
 static int			dotdot_update;
 
 static void
