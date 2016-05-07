--- src/netkeyer.c.orig	2016-01-16 17:45:20 UTC
+++ src/netkeyer.c
@@ -17,7 +17,9 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
-
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <string.h>
 #include <unistd.h>
