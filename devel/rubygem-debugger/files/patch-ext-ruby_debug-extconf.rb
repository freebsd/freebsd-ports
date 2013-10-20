--- ext/ruby_debug/extconf.rb.orig	2013-07-27 13:58:53.000000000 +0400
+++ ext/ruby_debug/extconf.rb	2013-07-27 14:01:30.000000000 +0400
@@ -13,7 +13,6 @@
 end
 
 require "mkmf"
-require "debugger/ruby_core_source"
 require 'fileutils'
 
 if RUBY_VERSION < "1.9"
@@ -84,7 +83,9 @@
 end
 
 dir_config("ruby")
-if !Debugger::RubyCoreSource.create_makefile_with_core(hdrs, "ruby_debug")
+if hdrs.call
+  create_makefile("ruby_debug")
+else
   STDERR.print("Makefile creation failed\n")
   STDERR.print("*************************************************************\n\n")
   STDERR.print("  NOTE: If your headers were not found, try passing\n")
