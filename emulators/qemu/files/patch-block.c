Index: qemu/block.c
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
 
@@ -103,14 +103,25 @@
 {
     int fd, ret, score, score_max;
     BlockDriver *drv1, *drv;
-    uint8_t buf[1024];
+    uint8_t *buf;
+    size_t bufsize = 1024;
+    u_int sectorsize = 512;
 
     fd = open(filename, O_RDONLY | O_BINARY | O_LARGEFILE);
     if (fd < 0)
         return NULL;
-    ret = read(fd, buf, sizeof(buf));
+#ifdef DIOCGSECTORSIZE
+    if (!ioctl(fd, DIOCGSECTORSIZE, &sectorsize) &&
+        sectorsize > bufsize)
+        bufsize = sectorsize;
+#endif
+    buf = malloc(bufsize);
+    if (!buf)
+        return NULL;
+    ret = read(fd, buf, bufsize);
     if (ret < 0) {
         close(fd);
+        free(buf);
         return NULL;
     }
     close(fd);
@@ -124,6 +135,7 @@
             drv = drv1;
         }
     }
+    free(buf);
     return drv;
 }
 
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
