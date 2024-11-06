--- libxfs/rdwr.c.orig	2015-07-24 04:28:04 UTC
+++ libxfs/rdwr.c
@@ -16,6 +16,7 @@
  * Inc.,  51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  */
 
+#include <inttypes.h>
 #include <xfs/libxfs.h>
 #include "init.h"
 
@@ -371,7 +372,7 @@ libxfs_bcompare(struct cache_node *node,
 #ifdef IO_BCOMPARE_CHECK
 		if (!(libxfs_bcache->c_flags & CACHE_MISCOMPARE_PURGE)) {
 			fprintf(stderr,
-	"%lx: Badness in key lookup (length)\n"
+	"%p: Badness in key lookup (length)\n"
 	"bp=(bno 0x%llx, len %u bytes) key=(bno 0x%llx, len %u bytes)\n",
 				pthread_self(),
 				(unsigned long long)bp->b_bn, (int)bp->b_bcount,
