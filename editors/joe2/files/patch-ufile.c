--- ufile.c.orig	Wed Sep 18 19:09:53 2002
+++ ufile.c	Wed Sep 18 19:10:19 2002
@@ -149,7 +149,7 @@
  f=open(from,O_RDONLY);
  if(f<0) return -1;
  if(fstat(f,&sbuf)<0) return -1;
- g=creat(to,sbuf.st_mode);
+ g=creat(to,sbuf.st_mode&~(S_ISGID|S_ISUID));
  if(g<0)
   {
   close(f);
