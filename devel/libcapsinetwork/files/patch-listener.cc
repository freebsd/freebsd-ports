$FreeBSD$

--- listener.cc.orig	Thu Oct 24 14:26:02 2002
+++ listener.cc	Thu Oct 24 14:34:19 2002
@@ -14,11 +14,13 @@
 // the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 // Boston, MA 02111-1307, USA.
 
-//#include <netinet/in.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/time.h>
+
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <netdb.h>
-#include <sys/socket.h>
-#include <sys/types.h>
 #include <unistd.h>
 
 #include "listener.h"
