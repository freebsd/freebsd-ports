--- lib/ipaddr.rb.orig	2008-08-10 14:32:15.000000000 +0400
+++ lib/ipaddr.rb	2008-08-10 14:32:58.000000000 +0400
@@ -438,7 +438,7 @@
     if prefixlen
       mask!(prefixlen)
     else
-      @mask_addr = (family == Socket::AF_INET) ? IN4MASK : IN6MASK
+      @mask_addr = (@family == Socket::AF_INET) ? IN4MASK : IN6MASK
     end
   end
 
