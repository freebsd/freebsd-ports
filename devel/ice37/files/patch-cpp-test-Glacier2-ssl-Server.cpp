--- cpp/test/Glacier2/ssl/Server.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/test/Glacier2/ssl/Server.cpp
@@ -31,9 +31,9 @@ void testContext(bool ssl, const Ice::CommunicatorPtr&
         port << TestHelper::getTestPort(communicator->getProperties(), 1);
         test(ctx["_con.localPort"] == port.str());
     }
-    test(ctx["_con.localAddress"] == "127.0.0.1");
+    test(ctx["_con.localAddress"] == "127.0.0.1" || inFreeBSDJail());
     test(ctx["_con.remotePort"] != "");
-    test(ctx["_con.remoteAddress"] == "127.0.0.1");
+    test(ctx["_con.remoteAddress"] == "127.0.0.1" || inFreeBSDJail());
 }
 
 }
@@ -125,8 +125,8 @@ class SSLSessionManagerI : public Glacier2::SSLSession
     {
         testContext(true, current.adapter->getCommunicator(), current.ctx);
 
-        test(info.remoteHost == "127.0.0.1");
-        test(info.localHost == "127.0.0.1");
+        test(info.remoteHost == "127.0.0.1" || inFreeBSDJail());
+        test(info.localHost == "127.0.0.1" || inFreeBSDJail());
         test(info.localPort == TestHelper::getTestPort(current.adapter->getCommunicator()->getProperties(), 1));
 
         try
