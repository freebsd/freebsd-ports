--- setup/FreeBSD/oss/build/osscore.c.orig	2008-01-14 12:51:36.000000000 -0500
+++ setup/FreeBSD/oss/build/osscore.c	2008-01-14 12:53:37.000000000 -0500
@@ -264,7 +264,7 @@
   *phaddr = 0;
 
   tmpbuf =
-    (char *) contigmalloc (buffsize, M_DEVBUF, M_NOWAIT, 0ul, memlimit,
+    (char *) contigmalloc (buffsize, M_DEVBUF, M_WAITOK, 0ul, memlimit,
 			   PAGE_SIZE, 0ul);
   if (tmpbuf == NULL)
     {
