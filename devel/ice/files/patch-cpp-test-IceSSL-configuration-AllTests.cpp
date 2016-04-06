--- cpp/test/IceSSL/configuration/AllTests.cpp.orig	2015-06-23 15:30:20.000000000 +0000
+++ cpp/test/IceSSL/configuration/AllTests.cpp	2015-09-15 00:15:34.865304987 +0000
@@ -3164,6 +3184,7 @@
 #endif
     }
 
+#if 0 // we don't want to talk to zeroc while building
     cout << "testing system CAs... " << flush;
     {
         InitializationData initData;
@@ -3208,6 +3229,7 @@
         comm->destroy();
     }
     cout << "ok" << endl;
+#endif
 
     if(shutdown)
     {
