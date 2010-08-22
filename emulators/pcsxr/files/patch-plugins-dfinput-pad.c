--- plugins/dfinput/pad.c.orig	2009-12-25 18:26:35.000000000 +0000
+++ plugins/dfinput/pad.c	2010-06-03 08:06:29.658820184 +0000
@@ -386,3 +386,6 @@
 long PADtest(void) {
 	return PSE_PAD_ERR_SUCCESS;
 }
+
+/* missing symbol : do nothing */
+void PADsetSensitive(int sensitive) {}
