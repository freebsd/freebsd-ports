--- ruby-install.rb.orig	Tue Feb 25 15:33:48 2003
+++ ruby-install.rb	Tue Feb 25 15:34:14 2003
@@ -857,7 +857,7 @@
 class ToplevelInstaller < Installer
 
   def self.invoke
-    new(File.dirname($0)).invoke
+    new(Dir.pwd).invoke
   end
 
 
