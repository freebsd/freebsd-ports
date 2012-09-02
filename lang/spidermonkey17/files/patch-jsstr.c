--- jsstr.c	2006-11-22 09:28:44.000000000 +0100
+++ jsstr.c	2008-06-19 16:14:49.000000000 +0200
@@ -1815,6 +1815,8 @@
     jsint i, j;
     uint32 len, limit;
 
+    bzero(&tmp,sizeof(tmp));
+
     str = js_ValueToString(cx, OBJECT_TO_JSVAL(obj));
     if (!str)
         return JS_FALSE;
