--- src/daemon/driver/driverControlers.ml.orig	Sun Mar  7 17:44:13 2004
+++ src/daemon/driver/driverControlers.ml	Tue Mar 23 11:31:09 2004
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
@@ -602,15 +604,15 @@
 let http_add_html_header r = 
   http_add_gen_header r;
   add_reply_header r "Pragma" "no-cache";
-  add_reply_header r "Content-Type" "text/html; charset=iso-8859-1"
+  add_reply_header r "Content-Type" "text/html; charset=big5"
 
 let http_add_css_header r = 
   http_add_gen_header r;
-  add_reply_header r "Content-Type" "text/css; charset=iso-8859-1"
+  add_reply_header r "Content-Type" "text/css; charset=big5"
 
 let http_add_js_header r =
   http_add_gen_header r;
-  add_reply_header  r "Content-Type" "text/javascript; charset=iso-8859-1"
+  add_reply_header  r "Content-Type" "text/javascript; charset=big5"
   
 let any_ip = Ip.of_inet_addr Unix.inet_addr_any
   
