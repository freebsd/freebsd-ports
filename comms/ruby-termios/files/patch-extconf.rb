--- extconf.rb.orig	2009-02-13 23:17:58.000000000 +0300
+++ extconf.rb	2009-02-13 23:18:05.000000000 +0300
@@ -3,7 +3,7 @@
 if have_header('termios.h') &&
     have_header('unistd.h')
 
-  unless RUBY_VERSION < '1.7' || have_type("rb_io_t", ["ruby.h", "rubyio.h"])
+  unless RUBY_VERSION < '1.7'
     have_struct_member("OpenFile", "fd", ["ruby.h", "rubyio.h"])
   end
 
