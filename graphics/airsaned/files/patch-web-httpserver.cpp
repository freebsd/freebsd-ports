--- web/httpserver.cpp.orig	2021-02-01 18:41:51 UTC
+++ web/httpserver.cpp
@@ -26,6 +26,9 @@ along with this program.  If not, see <http://www.gnu.
 #include <thread>
 
 #include <arpa/inet.h>
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
 #include <ifaddrs.h>
 #include <net/if.h>
 #include <netdb.h>
