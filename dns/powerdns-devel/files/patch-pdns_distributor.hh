--- pdns/distributor.hh.org	Wed Mar 15 19:29:38 2006
+++ pdns/distributor.hh	Wed Feb  7 19:42:24 2007
@@ -198,7 +198,7 @@
         return 0;
       }
       catch(...) {
-        L<<Logger::Error<<Logger::NTLog<<"Caught unknown exception in Distributor thread "<<(unsigned int)pthread_self()<<endl;
+        L<<Logger::Error<<Logger::NTLog<<"Caught unknown exception in Distributor thread "<<(unsigned long)pthread_self()<<endl;
 	delete b;
         return 0;
       }
