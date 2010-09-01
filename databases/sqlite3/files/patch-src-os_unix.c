--- src/os_unix.c.orig	2010-08-31 10:44:29.000000000 +0400
+++ src/os_unix.c	2010-08-31 10:44:48.000000000 +0400
@@ -4841,7 +4841,7 @@
   char *zErr;
   UNUSED_PARAMETER(NotUsed);
   unixEnterMutex();
-  zErr = dlerror();
+  zErr = (char *)dlerror();
   if( zErr ){
     sqlite3_snprintf(nBuf, zBufOut, "%s", zErr);
   }
