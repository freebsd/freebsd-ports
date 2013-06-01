--- extconf.rb.orig	2004-07-13 02:46:01.000000000 +0900
+++ extconf.rb	2013-05-02 15:17:55.000000000 +0900
@@ -5,9 +5,26 @@
 have_library('eb')
 have_func("rb_block_proc")
 have_func("eb_bitmap_to_png")
-have_header('eb/sysdefs.h')                                                    
+have_header('eb/sysdefs.h')
+have_type('rb_encoding', ['ruby/ruby.h', 'ruby/encoding.h'])
 
-# uncomment the following line if you use eb-4.0beta* with pthread support.
-# $defs << '-DEBCONF_ENABLE_PTHREAD'
+if have_func("eb_pthread_enabled")
+  print "checking that the EB library is pthread enabled... "
+  STDOUT.flush
+  if try_run(<<EOS)
+#include <eb/eb.h>
+
+int main()
+{
+    printf("eb_pthread_enabled() => %d\\n", eb_pthread_enabled());
+    return eb_pthread_enabled() ? 0 : 1;
+}
+EOS
+    puts "yes"
+    $defs << '-DRUBY_EB_ENABLE_PTHREAD'
+  else
+    puts "no"
+  end
+end
 
 create_makefile("eb")
