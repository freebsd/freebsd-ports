--- lib/fileutils.rb.orig	Sun Nov 20 02:23:41 2005
+++ lib/fileutils.rb	Mon Jan 16 02:08:47 2006
@@ -501,6 +501,7 @@
           File.rename s, d
         rescue Errno::EXDEV
           copy_entry s, d, true
+          File.unlink s
         end
       rescue SystemCallError
         raise unless options[:force]
