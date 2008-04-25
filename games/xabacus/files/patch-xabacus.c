--- xabacus.c.orig	2008-04-10 05:11:27.000000000 +0900
+++ xabacus.c	2008-04-10 23:09:23.000000000 +0900
@@ -1253,7 +1253,9 @@
 		XtNmono, &mono,
 		XtNreverseVideo, &reverse,
 		XtNmode, &mode,
+#ifdef LEE_ABACUS
 		XtNscript, &script,
+#endif
 		XtNdemoForeground, &demoForeground,
 		XtNdemoBackground, &demoBackground,
 		XtNdemoPath, &demoPath,
