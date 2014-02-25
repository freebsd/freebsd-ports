--- ./ext/dl/extconf.rb.orig   2010-02-25 22:49:20.000000000 +0000
+++ ./ext/dl/extconf.rb        2014-02-18 22:06:44.000000000 +0000
@@ -1,7 +1,8 @@
 require 'mkmf'

 if RbConfig::CONFIG['GCC'] == 'yes'
-  $CFLAGS << " -fno-defer-pop -fno-omit-frame-pointer"
+  $CFLAGS << " -fno-defer-pop" unless have_macro("__clang__")
+  $CFLAGS << " -fno-omit-frame-pointer"
 end

 $INSTALLFILES = [
