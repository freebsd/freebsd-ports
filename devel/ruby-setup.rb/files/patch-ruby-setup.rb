--- ruby-setup.rb.orig	Wed Aug 27 13:03:01 2003
+++ ruby-setup.rb	Thu Aug 28 01:16:03 2003
@@ -908,7 +908,7 @@
   @singleton = nil
 
   def ToplevelInstaller.instance
-    @singleton = new(File.dirname($0)) unless defined?(@singleton)
+    @singleton = new(File.pwd) unless defined?(@singleton)
     @singleton
   end
 
