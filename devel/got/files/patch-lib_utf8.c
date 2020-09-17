--- lib/utf8.c.orig	2020-09-10 16:01:39 UTC
+++ lib/utf8.c
@@ -15,6 +15,8 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#include <sys/types.h>
+
 #include <err.h>
 #include <stdlib.h>
 #include <string.h>
