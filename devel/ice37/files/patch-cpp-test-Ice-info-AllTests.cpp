--- cpp/test/Ice/info/AllTests.cpp.orig	2018-04-20 15:02:08 UTC
+++ cpp/test/Ice/info/AllTests.cpp
@@ -129,13 +129,13 @@ allTests(const Ice::CommunicatorPtr& com
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
 
@@ -218,8 +218,8 @@ allTests(const Ice::CommunicatorPtr& com
         test(info->remotePort == port);
         if(defaultHost == "127.0.0.1")
         {
-            test(info->remoteAddress == defaultHost);
-            test(info->localAddress == defaultHost);
+            test(info->remoteAddress == defaultHost || inFreeBSDJail());
+            test(info->localAddress == defaultHost || inFreeBSDJail());
         }
 #if !defined(ICE_OS_UWP)
         test(info->rcvSize >= 1024);
@@ -279,8 +279,8 @@ allTests(const Ice::CommunicatorPtr& com
         test(udpinfo->remotePort == port);
         if(defaultHost == "127.0.0.1")
         {
-            test(udpinfo->remoteAddress == defaultHost);
-            test(udpinfo->localAddress == defaultHost);
+            test(udpinfo->remoteAddress == defaultHost || inFreeBSDJail());
+            test(udpinfo->localAddress == defaultHost || inFreeBSDJail());
         }
 
 #if !defined(ICE_OS_UWP)
