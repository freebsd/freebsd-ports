--- unix/plugins/ScratchPlugin/unixSeriaPort2Ops.c.orig	2012-07-30 21:58:07 UTC
+++ unix/plugins/ScratchPlugin/unixSeriaPort2Ops.c
@@ -337,7 +337,7 @@ error:
 }
 
 int isSerialPortDev(char *s) {
-	return isPrefix("ttyusb", s);
+	return isPrefix("ttyU", s);
 }
 
 int isPrefix(char *prefix, char *s) {
