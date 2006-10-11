--- ext/textbuf/sftextbuf.c.orig	Thu Mar 15 01:30:08 2001
+++ ext/textbuf/sftextbuf.c	Wed Oct 11 09:07:55 2006
@@ -1158,7 +1158,6 @@
     OBJSETUP(str, rb_cString, T_STRING);
     str->ptr = 0;
     str->len = 0;
-    str->orig = 0;
     OBJ_FREEZE(str);
 
     CRITICAL_BEGIN(buf);
@@ -1199,7 +1198,6 @@
     OBJSETUP(str, rb_cString, T_STRING);
     str->ptr = 0;
     str->len = 0;
-    str->orig = 0;
     OBJ_FREEZE(str);
 
     CRITICAL_BEGIN(buf);
