--- upnp/src/genlib/net/http/httpreadwrite.c.orig	2021-02-25 14:08:26 UTC
+++ upnp/src/genlib/net/http/httpreadwrite.c
@@ -66,7 +66,6 @@
 		#define snprintf _snprintf
 	#endif
 #else /* _WIN32 */
-	#include <alloca.h>
 	#include <arpa/inet.h>
 	#include <sys/time.h>
 	#include <sys/types.h>
