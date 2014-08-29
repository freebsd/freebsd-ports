--- ./ext/extconf.rb.orig	2013-12-12 21:55:36.054257218 +0000
+++ ./ext/extconf.rb	2013-12-12 21:55:51.579256255 +0000
@@ -11,11 +11,9 @@
      $static = nil
   end
   
-  if RUBY_VERSION =~ /1.9/
-    $CFLAGS << ' -DRUBY_19_COMPATIBILITY'
-  end
+  $CFLAGS << ' -DRUBY_19_COMPATIBILITY'
   
   create_makefile('bzip2_ext')
 else
   puts "libbz2 not found, maybe try manually specifying --with-bz2-dir to find it?"
-end
\ No newline at end of file
+end
