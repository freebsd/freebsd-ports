--- install.rb.orig	Tue Oct 23 23:42:01 2001
+++ install.rb	Wed Oct 24 00:52:40 2001
@@ -18,12 +18,11 @@
 def install
   begin
     File.makedirs( DESTDIR )
-    Dir.chdir(SRC_BASE) do
+    Dir.chdir(SRC_BASE)
       Find.find(SRC) do |file|
 	dst = File.join( INSTDIR, file )
 	File.install(file, dst, 0644, true) if file =~ /.rb$/
       end
-    end
     rescue
       puts $!
     end
