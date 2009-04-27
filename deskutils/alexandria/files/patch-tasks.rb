--- tasks.rb.org	2009-04-15 08:01:49.000000000 +0900
+++ tasks.rb	2009-04-15 08:02:03.000000000 +0900
@@ -397,7 +397,7 @@
     end
 
     def manpage_installation
-      man_dir = File.join(File.join(sharedir, 'man'), 'man1')
+      man_dir = File.join(File.join(@prefix, 'man'), 'man1')
       [['doc', build.doc.man_files, man_dir, 0644]]
     end
 
