--- cpp/test/IceSSL/configuration/AllTests.cpp.orig	2015-06-27 18:39:22.443351407 +0000
+++ cpp/test/IceSSL/configuration/AllTests.cpp	2015-06-27 18:40:30.619349872 +0000
@@ -3164,6 +3164,7 @@
 #endif
     }
 
+#if 0 // we don't want to talk to zeroc while building
     cout << "testing system CAs... " << flush;
     {
         InitializationData initData;
@@ -3208,6 +3209,7 @@
         comm->destroy();
     }
     cout << "ok" << endl;
+#endif
 
     if(shutdown)
     {
