Index: server/net.h
===================================================================
--- server/net.h	(revision 741)
+++ server/net.h	(revision 742)
@@ -17,11 +17,18 @@
  *
  ******************************************************************************/
 
+#include <sys/types.h>
+#include <sys/socket.h>
+
 #include <stdlib.h>
 #include <unistd.h>
 
 #include <glib.h>
 
+#ifndef MSG_NOSIGNAL
+#define MSG_NOSIGNAL	0
+#endif
+
 extern const int proto_major;
 extern const int proto_minor;
 
