--- ime.c.orig	Fri Jan  9 21:37:21 2004
+++ ime.c	Fri Jan  9 21:36:57 2004
@@ -682,11 +682,11 @@
 
 void DoPhraseTips (void)
 {
-    if (!PhraseTips)
-	return;
-
     char            strTemp[MAX_HZ_SAVED * 2 + 1];
     INT8            count;
+
+    if (!PhraseTips)
+	return;
 
     strTemp[0] = '\0';
     for (count = 0; count < iHZLastInputCount; count++)
