--- cpp/test/Glacier2/ssl/Server.cpp.orig	2019-08-12 19:54:18 UTC
+++ cpp/test/Glacier2/ssl/Server.cpp
@@ -31,9 +31,15 @@ void testContext(bool ssl, const Ice::Context& context
         test(ctx["_con.type"] == "ssl");
         test(ctx["_con.localPort"] == "12348");
     }
-    test(ctx["_con.localAddress"] == "127.0.0.1");
+    if (!inFreeBSDJail())
+    {
+        test(ctx["_con.localAddress"] == "127.0.0.1");
+    }
     test(ctx["_con.remotePort"] != "");
-    test(ctx["_con.remoteAddress"] == "127.0.0.1");
+    if (!inFreeBSDJail())
+    {
+        test(ctx["_con.remoteAddress"] == "127.0.0.1");
+    }
 }
 
 }
@@ -125,8 +131,11 @@ class SSLSessionManagerI : public Glacier2::SSLSession
     {
         testContext(true, current.ctx);
 
-        test(info.remoteHost == "127.0.0.1");
-        test(info.localHost == "127.0.0.1");
+        if (!inFreeBSDJail())
+        {
+            test(info.remoteHost == "127.0.0.1");
+            test(info.localHost == "127.0.0.1");
+        }
         test(info.localPort == 12348);
 
         try
