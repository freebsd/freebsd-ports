--- common.c.orig	Thu Jul 17 19:20:43 2003
+++ common.c	Thu Jul 17 19:22:04 2003
@@ -123,7 +123,7 @@ int head_check(unsigned long head)
 	return FALSE;
     if(!((head>>17)&3))
 	return FALSE;
-    if( ((head>>12)&0xf) == 0xf)
+    if( ((head>>12)&0xf) == 0xf || ((head>>12)&0xf) == 0)
 	return FALSE;
     if( ((head>>10)&0x3) == 0x3 )
 	return FALSE;
