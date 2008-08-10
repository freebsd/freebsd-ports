--- lib/resolv-replace.rb.orig	2008-08-10 14:35:16.000000000 +0400
+++ lib/resolv-replace.rb	2008-08-10 14:35:40.000000000 +0400
@@ -23,7 +23,8 @@
 class UDPSocket
   alias original_resolv_bind bind
   def bind(host, port)
-    original_resolv_bind(IPSocket.getaddress(host), port)
+    host = IPSocket.getaddress(host) if host != ""
+    original_resolv_bind(host, port)
   end
 
   alias original_resolv_connect connect
