--- ext/extconf.rb.orig	2016-07-26 12:25:25 UTC
+++ ext/extconf.rb
@@ -11,11 +11,9 @@ if have_library("bz2", "BZ2_bzWriteOpen"
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
