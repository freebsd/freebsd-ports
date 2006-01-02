--- src/hotplug_generic.c.orig	Mon Aug  8 21:58:19 2005
+++ src/hotplug_generic.c	Sun Jan  1 17:34:00 2006
@@ -20,8 +20,15 @@
 #include "config.h"
 #include "pcsclite.h"
 
+#ifndef TRUE
+#define TRUE 1
+#define FALSE 0
+#endif
+
 #if !defined(__APPLE__) && !defined(HAVE_LIBUSB) && !defined(__linux__)
 
+char ReCheckSerialReaders = FALSE;
+
 LONG HPSearchHotPluggables(void)
 {
 	return 0;
@@ -35,6 +42,11 @@
 LONG HPStopHotPluggables(void)
 {
 	return 0;
+}
+
+void HPReCheckSerialReaders(void)
+{
+	ReCheckSerialReaders = TRUE;
 }
 
 #endif
