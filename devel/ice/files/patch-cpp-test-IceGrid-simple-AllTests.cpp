--- cpp/test/IceGrid/simple/AllTests.cpp.orig	2015-06-23 15:30:20.000000000 +0000
+++ cpp/test/IceGrid/simple/AllTests.cpp	2015-06-27 16:05:16.492987125 +0000
@@ -49,6 +49,7 @@
     cout << "ok" << endl;
 
     cout << "testing discovery... " << flush;
+    bool discoveryOk = true;
     {
         // Add test well-known object
         IceGrid::RegistryPrx registry = IceGrid::RegistryPrx::checkedCast(
@@ -77,15 +78,22 @@
         initData.properties->setProperty("AdapterForDiscoveryTest.Endpoints", "default");
 
         Ice::CommunicatorPtr com = Ice::initialize(initData);
-        test(com->getDefaultLocator());
-        com->stringToProxy("test @ TestAdapter")->ice_ping();
-        com->stringToProxy("test")->ice_ping();
 
-        test(com->getDefaultLocator()->getRegistry());
-        test(IceGrid::LocatorPrx::checkedCast(com->getDefaultLocator()));
-        test(IceGrid::LocatorPrx::uncheckedCast(com->getDefaultLocator())->getLocalRegistry());
-        test(IceGrid::LocatorPrx::uncheckedCast(com->getDefaultLocator())->getLocalQuery());
+        try
+        {
+            test(com->getDefaultLocator());
+            com->stringToProxy("test @ TestAdapter")->ice_ping();
+            com->stringToProxy("test")->ice_ping();
 
+            test(com->getDefaultLocator()->getRegistry());
+            test(IceGrid::LocatorPrx::checkedCast(com->getDefaultLocator()));
+            test(IceGrid::LocatorPrx::uncheckedCast(com->getDefaultLocator())->getLocalRegistry());
+            test(IceGrid::LocatorPrx::uncheckedCast(com->getDefaultLocator())->getLocalQuery());
+        }
+        catch(const Ice::NoEndpointException&)
+        {
+            discoveryOk = false;
+        }
         Ice::ObjectAdapterPtr adapter = com->createObjectAdapter("AdapterForDiscoveryTest");
         adapter->activate();
         adapter->deactivate();
@@ -131,7 +139,15 @@
 
         com->destroy();
     }
-    cout << "ok" << endl;
+
+    if (discoveryOk)
+    {
+        cout << "ok" << endl;
+    }
+    else
+    {
+        cout << "failed (is a firewall enabled?)" << endl;
+    }    
 
     cout << "shutting down server... " << flush;
     obj->shutdown();
