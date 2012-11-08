--- plugins/dfinput/pad.c.orig	2012-11-08 06:07:00.000000000 +0100
+++ plugins/dfinput/pad.c	2012-11-08 06:09:26.000000000 +0100
@@ -676,8 +676,6 @@
 	} else if (pid > 0) {
 		waitpid(pid, NULL, 0);
 	}
-
-	return PSE_PAD_ERR_SUCCESS;
 }
 
 #endif
@@ -685,3 +683,6 @@
 long PADtest(void) {
 	return PSE_PAD_ERR_SUCCESS;
 }
+
+/* missing symbol : do nothing */
+void PADsetSensitive(int sensitive) {}
