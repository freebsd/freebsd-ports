--- ext/tk/tkutil/extconf.rb.orig	2009-02-14 01:15:24.000000000 +0300
+++ ext/tk/tkutil/extconf.rb	2009-02-14 01:15:39.000000000 +0300
@@ -5,9 +5,7 @@
   has_tk = true
 end
 
-if has_tk
   require 'mkmf'
   have_func("rb_obj_instance_exec", "ruby.h")
   have_func("strndup", "string.h")
   create_makefile('tkutil')
-end
