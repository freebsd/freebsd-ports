--- core/threading/core.c.orig	2007-12-13 00:41:24.000000000 +0100
+++ core/threading/core.c	2007-12-13 00:41:47.000000000 +0100
@@ -17,7 +17,7 @@
 while ( buff[i] == head[i] )
    i++;
 
-while ( buff[i] != NULL )
+while ( buff[i] != '\0' )
    {
    SHRet[k] = buff[i];
    i++;
