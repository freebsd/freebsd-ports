--- socket/cork.c.orig	Wed Mar 13 02:00:20 2002
+++ socket/cork.c	Wed Mar 13 02:01:45 2002
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
 
@@ -25,10 +25,10 @@
 {
 #if defined(TCP_CORK)
   int flag = 1;
-  return setsockopt(sock, SOL_TCP, TCP_CORK, &flag, sizeof flag) == 0;
+  return setsockopt(sock, SOL_SOCKET, TCP_CORK, &flag, sizeof flag) == 0;
 #elif defined(TCP_NOPUSH)
   int flag = 1;
-  return setsockopt(sock, SOL_TCP, TCP_NOPUSH, &flag, sizeof flag) == 0;
+  return setsockopt(sock, SOL_SOCKET, TCP_NOPUSH, &flag, sizeof flag) == 0;
 #else
   return 1;
 #endif
