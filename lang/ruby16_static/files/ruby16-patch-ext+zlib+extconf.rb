--- ext/zlib/extconf.rb.orig	Fri Mar 28 11:24:47 2003
+++ ext/zlib/extconf.rb	Sun Apr 27 05:56:22 2003
@@ -24,7 +24,7 @@
   oldlibs = $libs
   oldlibpath = $LIBPATH
   $libs += " " + Config::CONFIG['LIBRUBYARG']
-  $LIBPATH = [$libdir, $archdir] | $LIBPATH
+  $LIBPATH = [$libdir, $archdir || Config::CONFIG["compile_dir"]] | $LIBPATH
   begin
     have_func s, 'ruby.h'
   rescue ArgumentError   # for ruby-1.4
