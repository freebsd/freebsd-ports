--- log_writer.rb.orig	Fri Dec 22 12:46:39 2000
+++ log_writer.rb	Mon Mar  5 16:05:06 2001
@@ -12,8 +12,7 @@
 
 def put_log(str)
   $loglock.synchronize do
-    $stdout.print(str)
-    $stdout.flush
+    $logout.print(str)
   end
 end
 
