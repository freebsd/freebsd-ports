--- polyp/packet.h.orig	Fri Oct 29 23:30:28 2004
+++ polyp/packet.h	Fri Oct 29 23:31:05 2004
@@ -22,8 +22,14 @@
   USA.
 ***/
 
+#ifdef HAVE_CONFIG_H
+#include <config.h>
+#endif
+
 #include <sys/types.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 struct pa_packet {
     enum { PA_PACKET_APPENDED, PA_PACKET_DYNAMIC } type;
