--- src/openct/proto-t1.h.orig	Wed Apr 20 15:15:06 2005
+++ src/openct/proto-t1.h	Wed Apr 20 15:15:25 2005
@@ -23,7 +23,9 @@
 #define __PROTO_T1_H__
 
 #include <unistd.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 enum {
 	IFD_PROTOCOL_RECV_TIMEOUT = 0x0000,
