--- plugins/dfinput/pad.c.orig	2013-04-17 16:44:04.000000000 +0200
+++ plugins/dfinput/pad.c	2013-04-17 16:46:50.000000000 +0200
@@ -683,3 +683,6 @@
 long PADtest(void) {
 	return PSE_PAD_ERR_SUCCESS;
 }
+
+/* missing symbol : do nothing */
+void PADsetSensitive(int sensitive) {}
