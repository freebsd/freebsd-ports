--- qemu/block.c.orig	Thu Sep 30 06:27:57 2004
+++ qemu/block.c	Thu Nov  4 23:19:37 2004
@@ -21,6 +21,17 @@
  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  * THE SOFTWARE.
  */
+
+#include "config-host.h"
+
+#ifdef _BSD
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <sys/ioctl.h>
+#include <sys/queue.h>
+#include <sys/disk.h>
+#endif
+
 #include "vl.h"
 #include "block_int.h"
 
@@ -522,6 +533,15 @@
             return -1;
         bs->read_only = 1;
     }
+#ifdef _BSD
+    struct stat sb;
+    if (!fstat(fd,&sb) && (S_IFCHR & sb.st_mode)) {
+#ifdef DIOCGMEDIASIZE
+        if (ioctl(fd, DIOCGMEDIASIZE, (off_t *)&size))
+#endif
+            size = lseek(fd, 0LL, SEEK_END);
+    } else
+#endif
     size = lseek(fd, 0, SEEK_END);
     bs->total_sectors = size / 512;
     s->fd = fd;
