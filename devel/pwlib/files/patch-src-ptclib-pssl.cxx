--- src/ptclib/pssl.cxx.orig	2011-04-17 14:36:07.000000000 +0700
+++ src/ptclib/pssl.cxx	2011-04-17 14:36:37.000000000 +0700
@@ -914,8 +914,7 @@
   InitialisationMutex.Signal();
 
   // create the new SSL context
-  SSL_METHOD * meth = SSLv23_method();
-  context  = SSL_CTX_new(meth);
+  context  = SSL_CTX_new(SSLv23_method());
   if (context == NULL)
     PSSLAssert("Error creating context: ");
 
