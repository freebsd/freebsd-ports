

--- patch-jsstr.c begins here ---
--- jsstr.c.orig	Mon Dec 22 01:13:07 2003
+++ jsstr.c	Mon May 28 10:46:21 2007
@@ -1830,6 +1830,8 @@
     jsdouble d;
     jsint i, j;
     uint32 len, limit;
+    
+    bzero(&tmp,sizeof(tmp));
 
     str = js_ValueToString(cx, OBJECT_TO_JSVAL(obj));
     if (!str)

--- patch-jsstr.c ends here ---



