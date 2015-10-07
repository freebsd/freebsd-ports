--- sope-core/NGStreams/NGActiveSocket.m.orig	2015-09-16 18:26:50 UTC
+++ sope-core/NGStreams/NGActiveSocket.m
@@ -19,6 +19,7 @@
   02111-1307, USA.
 */
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 
