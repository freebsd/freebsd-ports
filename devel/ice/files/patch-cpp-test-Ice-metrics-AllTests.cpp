--- cpp/test/Ice/metrics/AllTests.cpp.orig	2019-08-12 19:54:18 UTC
+++ cpp/test/Ice/metrics/AllTests.cpp
@@ -639,9 +639,12 @@ allTests(const Ice::CommunicatorPtr& communicator, con
         testAttribute(clientMetrics, clientProps, update, "Connection", "incoming", "false");
         testAttribute(clientMetrics, clientProps, update, "Connection", "adapterName", "");
         testAttribute(clientMetrics, clientProps, update, "Connection", "connectionId", "Con1");
-        testAttribute(clientMetrics, clientProps, update, "Connection", "localHost", "127.0.0.1");
+        if (!inFreeBSDJail())
+        {
+            testAttribute(clientMetrics, clientProps, update, "Connection", "localHost", "127.0.0.1");
+            testAttribute(clientMetrics, clientProps, update, "Connection", "remoteHost", "127.0.0.1");
+        }
         //testAttribute(clientMetrics, clientProps, update, "Connection", "localPort", "");
-        testAttribute(clientMetrics, clientProps, update, "Connection", "remoteHost", "127.0.0.1");
         testAttribute(clientMetrics, clientProps, update, "Connection", "remotePort", "12010");
         testAttribute(clientMetrics, clientProps, update, "Connection", "mcastHost", "");
         testAttribute(clientMetrics, clientProps, update, "Connection", "mcastPort", "");
@@ -726,7 +729,7 @@ allTests(const Ice::CommunicatorPtr& communicator, con
         bool dnsException = false;
         try
         {
-            communicator->stringToProxy("test:tcp -t 500 -p 12010 -h unknownfoo.zeroc.com")->ice_ping();
+            communicator->stringToProxy("test:tcp -t 500 -p 12010 -h unknownhost9999.example.org")->ice_ping();
             test(false);
         }
         catch(const Ice::DNSException&)
@@ -739,7 +742,7 @@ allTests(const Ice::CommunicatorPtr& communicator, con
         }
         test(clientMetrics->getMetricsView("View", timestamp)["EndpointLookup"].size() == 2);
         m1 = clientMetrics->getMetricsView("View", timestamp)["EndpointLookup"][1];
-        test(m1->id == "tcp -h unknownfoo.zeroc.com -p 12010 -t 500" && m1->total == 2 &&
+        test(m1->id == "tcp -h unknownhost9999.example.org -p 12010 -t 500" && m1->total == 2 &&
              (!dnsException || m1->failures == 2));
         if(dnsException)
         {
@@ -871,9 +874,12 @@ allTests(const Ice::CommunicatorPtr& communicator, con
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "incoming", "true", op);
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "adapterName", "TestAdapter", op);
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "connectionId", "", op);
-        testAttribute(serverMetrics, serverProps, update, "Dispatch", "localHost", "127.0.0.1", op);
+        if (!inFreeBSDJail())
+        {
+            testAttribute(serverMetrics, serverProps, update, "Dispatch", "localHost", "127.0.0.1", op);
+            testAttribute(serverMetrics, serverProps, update, "Dispatch", "remoteHost", "127.0.0.1", op);
+        }
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "localPort", "12010", op);
-        testAttribute(serverMetrics, serverProps, update, "Dispatch", "remoteHost", "127.0.0.1", op);
         //testAttribute(serverMetrics, serverProps, update, "Dispatch", "remotePort", "12010", op);
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "mcastHost", "", op);
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "mcastPort", "", op);
