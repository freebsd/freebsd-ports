$FreeBSD$

--- listenport.cc.orig	Thu Oct 24 14:36:09 2002
+++ listenport.cc	Thu Oct 24 14:36:27 2002
@@ -15,12 +15,12 @@
 // Boston, MA 02111-1307, USA.
 
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h>
 #include <fcntl.h>
 #include <netdb.h>
-//#include <netinet/in.h>
-#include <sys/socket.h>
-#include <sys/types.h>
+#include <netinet/in.h>
 #include <unistd.h>
 
 #include "listenport.h"
