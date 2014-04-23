--- echolib/EchoLinkDispatcher.h.orig	2014-04-10 02:13:14.000000000 -0700
+++ echolib/EchoLinkDispatcher.h	2014-04-10 02:22:41.000000000 -0700
@@ -215,7 +215,8 @@
 	return a1 < a2;
       }
     };
-    typedef std::map<Async::IpAddress, ConData, ipaddr_lt> ConMap;
+    //typedef std::map<Async::IpAddress, ConData, ipaddr_lt> ConMap;
+    typedef std::map<Async::IpAddress, ConData> ConMap;
     
     static const int  	DEFAULT_PORT_BASE = 5198;
     
