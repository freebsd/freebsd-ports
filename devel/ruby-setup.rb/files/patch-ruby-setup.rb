--- ruby-setup.rb.orig	Tue May  7 13:52:44 2002
+++ ruby-setup.rb	Sat May 25 11:06:36 2002
@@ -1121,3 +1121,3 @@
   begin
-    installer = PackageManager.new( File.dirname($0) )
+    installer = PackageManager.new( Dir.pwd )
     installer.execute
