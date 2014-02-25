--- ext/dl/extconf.rb.orig	2014-02-24 15:49:13.436431209 +0000
+++ ext/dl/extconf.rb	2014-02-24 15:50:21.287476923 +0000
@@ -1,7 +1,7 @@
 require 'mkmf'
 
 if RbConfig::CONFIG['GCC'] == 'yes'
-  (have_macro("__clang__") ? $LDFLAGS : $CFLAGS) << " -fno-defer-pop"
+  $CFLAGS << " -fno-defer-pop" unless have_macro("__clang__")
   $CFLAGS << " -fno-omit-frame-pointer"
 end
 
