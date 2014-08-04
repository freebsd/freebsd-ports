--- unix/plugins/ScratchPlugin/unixSeriaPort2Ops.c.org	2012-09-24 15:26:44.000000000 +0900
+++ unix/plugins/ScratchPlugin/unixSeriaPort2Ops.c	2012-09-24 15:26:54.000000000 +0900
@@ -337,7 +337,7 @@
 }
 
 int isSerialPortDev(char *s) {
-	return isPrefix("ttyusb", s);
+	return isPrefix("ttyU", s);
 }
 
 int isPrefix(char *prefix, char *s) {
