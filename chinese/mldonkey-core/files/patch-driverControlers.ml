--- src/daemon/driver/driverControlers.ml.orig	Mon Oct 13 02:41:30 2003
+++ src/daemon/driver/driverControlers.ml	Wed Mar 10 19:11:04 2004
@@ -291,6 +291,7 @@
   }
 
 
+let iac_will_8bit = "\255\253\000"  
 let iac_will_naws = "\255\253\031"  
   
 let user_reader o telnet sock nread  = 
@@ -320,7 +321,7 @@
       
       let i = int_of_char c in
       telnet.telnet_iac <- false;
-      let is_normal_char = i > 31 && i < 127 in
+      let is_normal_char = i > 31 (*&& i < 127*) in
       
       if telnet.telnet_wait = 1 then begin
           Buffer.add_char telnet.telnet_buffer c;
@@ -439,6 +440,7 @@
         TcpBufferedSocket.set_closer sock user_closed;
         user_socks := sock :: !user_socks;
 
+        TcpBufferedSocket.write_string sock iac_will_8bit;
         TcpBufferedSocket.write_string sock iac_will_naws;
 
         before_telnet_output o sock;
@@ -573,17 +575,17 @@
 let http_add_html_header buf = 
   http_add_gen_header buf;
   Buffer.add_string  buf "Pragma: no-cache\r\n";
-  Buffer.add_string  buf "Content-Type: text/html; charset=iso-8859-1\r\n";
+  Buffer.add_string  buf "Content-Type: text/html; charset=big5\r\n";
   Buffer.add_string  buf "\r\n"
 
 let http_add_css_header buf = 
   http_add_gen_header buf;
-  Buffer.add_string  buf "Content-Type: text/css; charset=iso-8859-1\r\n";
+  Buffer.add_string  buf "Content-Type: text/css; charset=big5\r\n";
   Buffer.add_string  buf "\r\n"
 
 let http_add_js_header buf =
   http_add_gen_header buf;
-  Buffer.add_string  buf "Content-Type: text/javascript; charset=iso-8859-1\r\n";
+  Buffer.add_string  buf "Content-Type: text/javascript; charset=big5\r\n";
   Buffer.add_string  buf "\r\n"
 
 let any_ip = Ip.of_inet_addr Unix.inet_addr_any
