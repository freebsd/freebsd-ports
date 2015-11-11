--- sope-core/NGStreams/NGActiveSocket.m.orig	2015-09-16 18:26:50 UTC
+++ sope-core/NGStreams/NGActiveSocket.m
@@ -19,6 +19,7 @@
   02111-1307, USA.
 */
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 
@@ -410,7 +411,7 @@
   if ([self isConnected]) {
     [[[NGSocketAlreadyConnectedException alloc]
               initWithReason:@"Could not connected: socket is already connected"
-              socket:self address:self->remoteAddress] raise];
+              socket:self] raise];
     return NO;
   }
 
@@ -748,10 +749,7 @@
     if ((readResult < 0) && (errno == EINVAL)) {
       NSLog(@"%s: invalid argument in NGDescriptorRecv(%i, 0x%p, %i, %i)",
             __PRETTY_FUNCTION__,
-            self->fd, _buf, _len, 0,
-            (self->receiveTimeout == 0.0)
-            ? -1 // block until data
-            : (int)(self->receiveTimeout * 1000.0));
+            self->fd, _buf, _len, 0);
     }
 #endif
     
