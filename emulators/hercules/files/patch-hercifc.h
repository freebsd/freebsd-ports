--- hercifc.h.orig	2017-03-26 19:44:49 UTC
+++ hercifc.h
@@ -73,7 +73,11 @@
 // --------------------------------------------------------------------
 
 #define  HERCIFC_CMD  "hercifc"           // Interface config command
+#if defined(__FreeBSD__)
+#define  HERCTUN_DEV  "/dev/tun"          // Default TUN control dev
+#else
 #define  HERCTUN_DEV  "/dev/net/tun"      // Default TUN/TAP char dev
+#endif
 
 typedef struct _CTLREQ
 {
