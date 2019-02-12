--- cpp/test/Glacier2/ssl/Server.cpp.orig	2018-04-20 15:02:08 UTC
+++ cpp/test/Glacier2/ssl/Server.cpp
@@ -35,9 +35,9 @@ void testContext(bool ssl, const Ice::Co
         port << getTestPort(communicator->getProperties(), 1);
         test(ctx["_con.localPort"] == port.str());
     }
-    test(ctx["_con.localAddress"] == "127.0.0.1");
+    test(ctx["_con.localAddress"] == "127.0.0.1" || inFreeBSDJail());
     test(ctx["_con.remotePort"] != "");
-    test(ctx["_con.remoteAddress"] == "127.0.0.1");
+    test(ctx["_con.remoteAddress"] == "127.0.0.1" || inFreeBSDJail());
 }
 
 }
@@ -129,8 +129,8 @@ public:
     {
         testContext(true, current.adapter->getCommunicator(), current.ctx);
 
-        test(info.remoteHost == "127.0.0.1");
-        test(info.localHost == "127.0.0.1");
+        test(info.remoteHost == "127.0.0.1" || inFreeBSDJail());
+        test(info.localHost == "127.0.0.1" || inFreeBSDJail());
         test(info.localPort == TestHelper::getTestPort(current.adapter->getCommunicator()->getProperties(), 1));
 
         try
