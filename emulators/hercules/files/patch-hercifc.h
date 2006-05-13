--- hercifc.h.orig	Fri Feb 24 18:36:35 2006
+++ hercifc.h	Fri Feb 24 18:39:41 2006
@@ -77,7 +77,11 @@
 // --------------------------------------------------------------------
 
 #define  HERCIFC_CMD  "hercifc"           // Interface config command
+#if defined(__FreeBSD__)
+#define  HERCTUN_DEV  "/dev/tun"          // Default TUN control dev
+#else
 #define  HERCTUN_DEV  "/dev/net/tun"      // Default TUN/TAP char dev
+#endif
 
 typedef struct _CTLREQ
 {
