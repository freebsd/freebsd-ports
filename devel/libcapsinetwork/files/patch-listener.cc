$FreeBSD$

--- listener.cc.orig	Sat Jul 13 00:06:34 2002
+++ listener.cc	Sat Jul 13 00:06:36 2002
@@ -14,6 +14,7 @@
 // the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 // Boston, MA 02111-1307, USA.
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
