
$FreeBSD$

--- execinfo.c	2003/08/10 06:14:30	1.1
+++ execinfo.c	2003/08/10 06:15:23
@@ -41,8 +41,11 @@
 {
     int i;
 
-    for (i = 1; getframeaddr(i + 1) != NULL && i != size + 1; i++)
+    for (i = 1; getframeaddr(i + 1) != NULL && i != size + 1; i++) {
         buffer[i - 1] = getreturnaddr(i);
+        if (buffer[i - 1] == NULL)
+            break;
+    }
 
     return i - 1;
 }
