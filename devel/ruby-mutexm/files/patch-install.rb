--- install.rb.orig	Thu Jul 27 02:58:38 2000
+++ install.rb	Wed Feb 21 13:54:38 2001
@@ -64,7 +64,7 @@
     for f in files
       next if (f = f[srcdir.length+1..-1]) == nil
       path.push f if File.ftype(File.join(srcdir, f)) == 'file'
-      dir |= File.dirname(File.join(destdir, f))
+      dir |= [ File.dirname(File.join(destdir, f)) ]
     end
     @ftools.makedirs(*dir)
     for f in path
