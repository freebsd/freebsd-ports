--- include/sccp/sccp_types.h.org
+++ include/sccp/sccp_types.h
@@ -24,7 +24,11 @@
 #ifndef SCCP_TYPES_H
 #define SCCP_TYPES_H
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 
 /* Table 1/Q.713 - SCCP message types */
 enum sccp_message_types {
