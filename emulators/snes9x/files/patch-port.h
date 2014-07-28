--- port.h.orig	Fri Jun 30 08:40:56 2006
+++ port.h	Tue Dec 26 23:09:22 2006
@@ -360,6 +360,10 @@
 #define SYS_CONFIG_FILE "/etc/snes9x/snes9x.conf"
 #endif
 
+#ifdef __FreeBSD__
+#define TITLE "Snes9X: FreeBSD"
+#endif
+
 #ifndef TITLE
 #define TITLE "Snes9x"
 #endif
