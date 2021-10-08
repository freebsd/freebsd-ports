--- web/httpserver.cpp.orig	2021-10-05 12:35:03 UTC
+++ web/httpserver.cpp
@@ -25,6 +25,9 @@ along with this program.  If not, see <http://www.gnu.
 #include <thread>
 
 #include <arpa/inet.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include <ifaddrs.h>
 #include <net/if.h>
 #include <netdb.h>
