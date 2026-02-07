--- cpp/test/Ice/info/AllTests.cpp.orig	2023-11-06 09:24:19 UTC
+++ cpp/test/Ice/info/AllTests.cpp
@@ -116,13 +116,13 @@ allTests(Test::TestHelper* helper)
             test(ipEndpoint);
             test(ipEndpoint->type() == Ice::TCPEndpointType || ipEndpoint->type() == Ice::SSLEndpointType ||
                 ipEndpoint->type() == Ice::WSEndpointType || ipEndpoint->type() == Ice::WSSEndpointType);
-            test(ipEndpoint->host == "127.0.0.1");
+            test(ipEndpoint->host == "127.0.0.1" || inFreeBSDJail());
             test(ipEndpoint->port > 0);
             test(ipEndpoint->timeout == 15000);
 
             Ice::UDPEndpointInfoPtr udpEndpoint = ICE_DYNAMIC_CAST(Ice::UDPEndpointInfo, endpoints[1]->getInfo());
             test(udpEndpoint);
-            test(udpEndpoint->host == "127.0.0.1");
+            test(udpEndpoint->host == "127.0.0.1" || inFreeBSDJail());
             test(udpEndpoint->datagram());
             test(udpEndpoint->port > 0);
 
@@ -205,8 +205,8 @@ allTests(Test::TestHelper* helper)
         test(info->remotePort == port);
         if(defaultHost == "127.0.0.1")
         {
-            test(info->remoteAddress == defaultHost);
-            test(info->localAddress == defaultHost);
+            test(info->remoteAddress == defaultHost || inFreeBSDJail());
+            test(info->localAddress == defaultHost || inFreeBSDJail());
         }
         test(info->rcvSize >= 1024);
         test(info->sndSize >= 2048);
@@ -264,8 +264,8 @@ allTests(Test::TestHelper* helper)
         test(udpinfo->remotePort == port);
         if(defaultHost == "127.0.0.1")
         {
-            test(udpinfo->remoteAddress == defaultHost);
-            test(udpinfo->localAddress == defaultHost);
+            test(udpinfo->remoteAddress == defaultHost || inFreeBSDJail());
+            test(udpinfo->localAddress == defaultHost || inFreeBSDJail());
         }
         test(udpinfo->rcvSize >= 2048);
         test(udpinfo->sndSize >= 1024);
