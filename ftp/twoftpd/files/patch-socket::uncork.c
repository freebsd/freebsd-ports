--- socket/uncork.c.orig	Wed Mar 13 02:02:05 2002
+++ socket/uncork.c	Wed Mar 13 02:02:35 2002
@@ -15,9 +15,9 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
-#include <sys/types.h>
 #include <sys/socket.h>
 #include "socket.h"
 
@@ -25,13 +25,13 @@
 {
 #if defined(TCP_CORK)
   int flag = 0;
-  return setsockopt(sock, SOL_TCP, TCP_CORK, &flag, sizeof flag) == 0;
+  return setsockopt(sock, SOL_SOCKET, TCP_CORK, &flag, sizeof flag) == 0;
 #elif defined(TCP_NOPUSH)
   /* BSD's TCP_NOPUSH option only takes effect after a write/send.
    * Hopefully this extra write will cause the TCP stack to send out
    * any buffered writes. */
   int flag = 0;
-  if (setsockopt(sock, SOL_TCP, TCP_NOPUSH, &flag, sizeof flag) != 0) return 0;
+  if (setsockopt(sock, SOL_SOCKET, TCP_NOPUSH, &flag, sizeof flag) != 0) return 0;
   return write(sock, &flag, 0) == 0;
 #else
   return 1;
