--- cpp/test/Ice/info/AllTests.cpp.orig	2019-08-12 19:54:18 UTC
+++ cpp/test/Ice/info/AllTests.cpp
@@ -170,7 +170,7 @@ allTests(const Ice::CommunicatorPtr& communicator)
         test(info->adapterName.empty());
         test(info->localPort > 0);
         test(info->remotePort == 12010);
-        if(defaultHost == "127.0.0.1")
+        if(defaultHost == "127.0.0.1" && !inFreeBSDJail())
         {
             test(info->remoteAddress == defaultHost);
             test(info->localAddress == defaultHost);
@@ -234,7 +234,7 @@ allTests(const Ice::CommunicatorPtr& communicator)
         test(info->adapterName.empty());
         test(info->localPort > 0);
         test(info->remotePort == 12010);
-        if(defaultHost == "127.0.0.1")
+        if(defaultHost == "127.0.0.1" && !inFreeBSDJail())
         {
             test(info->remoteAddress == defaultHost);
             test(info->localAddress == defaultHost);
