--- src/split.h~	Mon Aug 20 13:39:26 2001
+++ src/split.h	Wed Apr 24 09:53:38 2002
@@ -26,8 +26,8 @@
 } SplitStatus;
 
 typedef struct _TimeData {
-	int start;
-	int end;
+	guint32 start;
+	guint32 end;
 } TimeData;
 
 typedef struct _SplitDialog {
