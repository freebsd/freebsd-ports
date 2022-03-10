--- ext/extconf.rb.orig	2022-03-10 08:57:25 UTC
+++ ext/extconf.rb
@@ -2,8 +2,8 @@ require 'mkmf'
 
 dir_config("iobuffer")
 have_library("c", "main")
-if have_macro("HAVE_RB_IO_T", "rubyio.h")
-  have_struct_member("rb_io_t", "fd", "rubyio.h")
+if have_macro("HAVE_RB_IO_T", "ruby/io.h")
+  have_struct_member("rb_io_t", "fd", "ruby/io.h")
 end
 
 create_makefile("iobuffer_ext")
