--- echolib/EchoLinkDirectoryCon.cpp.orig	2014-04-09 23:13:08.000000000 -0700
+++ echolib/EchoLinkDirectoryCon.cpp	2014-04-09 23:13:15.000000000 -0700
@@ -204,7 +204,7 @@
     }
     else
     {
-      errno = ECOMM;
+      errno = EIO;
       return -1;
     }
   }
