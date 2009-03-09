--- parser/cduce_curl.ml	2008-02-25 11:10:42.000000000 +0100
+++ parser/cduce_curl.ml	2009-02-13 16:52:26.000000000 +0100
@@ -9,7 +9,14 @@
     let buff = Buffer.create 4096 in 
     let conn = Curl.init () in
     Curl.set_url conn s;
-    Curl.set_writefunction conn (Buffer.add_string buff);
+    Curl.set_writefunction conn (
+      fun str ->
+	try
+          Buffer.add_string buff str;
+	  String.length str
+	with
+	    Failure _ -> 0
+      );
     Curl.perform conn;
     Buffer.contents buff
   with Curl.CurlException (code, n, msg) ->
