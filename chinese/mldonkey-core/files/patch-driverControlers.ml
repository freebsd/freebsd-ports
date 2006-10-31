--- src/daemon/driver/driverControlers.ml.orig	Thu Aug 19 15:56:53 2004
+++ src/daemon/driver/driverControlers.ml	Thu Jun 30 19:25:24 2005
@@ -319,6 +319,7 @@
   }
 
 
+let iac_will_8bit = "\255\253\000"  
 let iac_will_naws = "\255\253\031"
 
 let user_reader o telnet sock nread  = 
@@ -348,7 +349,7 @@
       
       let i = int_of_char c in
       telnet.telnet_iac <- false;
-      let is_normal_char = i > 31 && i < 127 in
+      let is_normal_char = i > 31 (*&& i < 127*) in
 
       if telnet.telnet_wait = 1 then begin
           Buffer.add_char telnet.telnet_buffer c;
@@ -469,6 +470,7 @@
         TcpBufferedSocket.set_closer sock user_closed;
         user_socks := sock :: !user_socks;
 
+        TcpBufferedSocket.write_string sock iac_will_8bit;
         TcpBufferedSocket.write_string sock iac_will_naws;
 
         before_telnet_output o sock;
