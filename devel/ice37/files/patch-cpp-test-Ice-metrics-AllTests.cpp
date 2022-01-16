--- cpp/test/Ice/metrics/AllTests.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/test/Ice/metrics/AllTests.cpp
@@ -858,9 +858,12 @@ allTests(Test::TestHelper* helper, const CommunicatorO
         testAttribute(clientMetrics, clientProps, update.get(), "Connection", "incoming", "false");
         testAttribute(clientMetrics, clientProps, update.get(), "Connection", "adapterName", "");
         testAttribute(clientMetrics, clientProps, update.get(), "Connection", "connectionId", "Con1");
-        testAttribute(clientMetrics, clientProps, update.get(), "Connection", "localHost", host);
-        //testAttribute(clientMetrics, clientProps, update.get(), "Connection", "localPort", "");
-        testAttribute(clientMetrics, clientProps, update.get(), "Connection", "remoteHost", host);
+        if (!inFreeBSDJail())
+        {
+            testAttribute(clientMetrics, clientProps, update.get(), "Connection", "localHost", host);
+            //testAttribute(clientMetrics, clientProps, update.get(), "Connection", "localPort", "");
+            testAttribute(clientMetrics, clientProps, update.get(), "Connection", "remoteHost", host);
+        }
         testAttribute(clientMetrics, clientProps, update.get(), "Connection", "remotePort", port);
         testAttribute(clientMetrics, clientProps, update.get(), "Connection", "mcastHost", "");
         testAttribute(clientMetrics, clientProps, update.get(), "Connection", "mcastPort", "");
@@ -949,7 +952,7 @@ allTests(Test::TestHelper* helper, const CommunicatorO
         bool dnsException = false;
         try
         {
-            communicator->stringToProxy("test:tcp -t 500 -h unknownfoo.zeroc.com -p " + port)->ice_ping();
+            communicator->stringToProxy("test:tcp -t 500 -h unknownhost9999.example.org -p " + port)->ice_ping();
             test(false);
         }
         catch(const Ice::DNSException&)
@@ -962,7 +965,7 @@ allTests(Test::TestHelper* helper, const CommunicatorO
         }
         test(clientMetrics->getMetricsView("View", timestamp)["EndpointLookup"].size() == 2);
         m1 = clientMetrics->getMetricsView("View", timestamp)["EndpointLookup"][1];
-        test(m1->id == "tcp -h unknownfoo.zeroc.com -p " + port + " -t 500" && m1->total == 2 &&
+        test(m1->id == "tcp -h unknownhost9999.example.org -p " + port + " -t 500" && m1->total == 2 &&
              (!dnsException || m1->failures == 2));
         if(dnsException)
         {
@@ -1093,9 +1096,11 @@ allTests(Test::TestHelper* helper, const CommunicatorO
         testAttribute(serverMetrics, serverProps, update.get(), "Dispatch", "incoming", "true", op);
         testAttribute(serverMetrics, serverProps, update.get(), "Dispatch", "adapterName", "TestAdapter", op);
         testAttribute(serverMetrics, serverProps, update.get(), "Dispatch", "connectionId", "", op);
-        testAttribute(serverMetrics, serverProps, update.get(), "Dispatch", "localHost", host, op);
+        if (!inFreeBSDJail())
+            testAttribute(serverMetrics, serverProps, update.get(), "Dispatch", "localHost", host, op);
         testAttribute(serverMetrics, serverProps, update.get(), "Dispatch", "localPort", port, op);
-        testAttribute(serverMetrics, serverProps, update.get(), "Dispatch", "remoteHost", host, op);
+        if (!inFreeBSDJail())
+            testAttribute(serverMetrics, serverProps, update.get(), "Dispatch", "remoteHost", host, op);
         //testAttribute(serverMetrics, serverProps, update.get(), "Dispatch", "remotePort", port, op);
         testAttribute(serverMetrics, serverProps, update.get(), "Dispatch", "mcastHost", "", op);
         testAttribute(serverMetrics, serverProps, update.get(), "Dispatch", "mcastPort", "", op);
