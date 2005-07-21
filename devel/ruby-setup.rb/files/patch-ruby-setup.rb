--- ruby-setup.rb.orig	Tue Dec 16 18:45:36 2003
+++ ruby-setup.rb	Mon Dec 22 03:02:04 2003
@@ -916,7 +916,7 @@
   @singleton = nil
 
   def ToplevelInstaller.instance
-    @singleton ||= new(File.dirname($0))
+    @singleton ||= new(Dir.pwd)
     @singleton
   end
 
