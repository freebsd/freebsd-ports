--- ruby-install.rb.orig	Tue May  7 13:52:44 2002
+++ ruby-install.rb	Sat May 25 11:06:48 2002
@@ -1006,3 +1006,3 @@
   begin
-    installer = ToplevelInstaller.new( File.dirname($0) )
+    installer = ToplevelInstaller.new( Dir.pwd )
     installer.execute
