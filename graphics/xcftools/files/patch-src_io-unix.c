--- src/io-unix.c.orig	2013-02-12 19:30:10.000000000 +0100
+++ src/io-unix.c	2014-09-11 01:34:41.000000000 +0200
@@ -96,7 +96,7 @@
       if( status > 0 ) {
         fclose(xcfstream) ;
         xcfstream = 0 ;
-        FatalGeneric(status,NULL);
+        FatalGeneric(status,"status=%d",status);
       }
     } else {
       fclose(xcfstream) ;
