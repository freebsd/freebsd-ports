--- util.rb.orig	Fri Dec 22 12:46:39 2000
+++ util.rb	Mon Mar  5 13:53:57 2001
@@ -27,7 +27,7 @@
 #
 # ex) "127.0.0.1" => "\x7f\x0\x0\x1"
 def str_to_ipstr(str)
-  arr = str.split(".").filter{|i| i.to_i}
+  arr = str.split(".").collect{|i| i.to_i}
 
   if arr.length != 4
     put_log("ipaddr invalid\n")
