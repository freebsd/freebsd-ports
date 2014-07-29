--- src/aaprintf.c.orig	Thu Apr 26 23:37:31 2001
+++ src/aaprintf.c	Sat Mar  2 22:54:56 2002
@@ -7,7 +7,7 @@
   char buf[1025];
   int i;
   va_start(args,fmt);
-  i=vsprintf(buf,fmt,args);
+  i=vsnprintf(buf,sizeof(buf),fmt,args);
   va_end(args);
   aa_puts(c,x,y,attr,buf);
   return i;
