--- lib/soap/mimemessage.rb	2009/05/26 12:20:36	23586
+++ lib/soap/mimemessage.rb	2009/05/26 12:22:37	23587
@@ -232,7 +232,7 @@
   end
 
   def to_s
-    str = headers_str + "\r\n\r\n" + conent_str
+    str = headers_str + "\r\n\r\n" + content_str
   end
 end
 
