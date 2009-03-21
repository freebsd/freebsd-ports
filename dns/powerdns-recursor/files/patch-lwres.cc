--- lwres.cc.orig	2008-06-24 22:23:33.000000000 +0400
+++ lwres.cc	2009-03-19 23:25:35.000000000 +0300
@@ -181,7 +181,7 @@
     
     return 1;
   }
-  catch(exception &mde) {
+  catch(std::exception &mde) {
     if(::arg().mustDo("log-common-errors"))
       L<<Logger::Notice<<"Unable to parse packet from remote server "<<ip.toString()<<": "<<mde.what()<<endl;
   }
