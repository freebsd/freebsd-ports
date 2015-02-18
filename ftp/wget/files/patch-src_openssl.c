--- src/openssl.c.orig	2014-11-10 10:40:17.596091395 +0100
+++ src/openssl.c	2014-11-10 10:41:08.186093629 +0100
@@ -89,11 +89,6 @@
   if (RAND_status ())
     return;
 
-  /* Get random data from EGD if opt.egd_file was used.  */
-  if (opt.egd_file && *opt.egd_file)
-    RAND_egd (opt.egd_file);
-
-  if (RAND_status ())
     return;
 
 #ifdef WINDOWS
