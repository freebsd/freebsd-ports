--- tool/mkconfig.rb.orig	2010-10-04 00:53:53.000000000 -0700
+++ tool/mkconfig.rb	2010-10-04 00:55:18.000000000 -0700
@@ -136,7 +136,8 @@
 
 drive = File::PATH_SEPARATOR == ';'
 
-prefix = "/lib/ruby/#{version}/#{arch}"
+major, minor, *rest = RUBY_VERSION.split('.')
+prefix = "/lib/ruby/#{major}.#{minor}/#{arch}"
 print "  TOPDIR = File.dirname(__FILE__).chomp!(#{prefix.dump})\n"
 print "  DESTDIR = ", (drive ? "TOPDIR && TOPDIR[/\\A[a-z]:/i] || " : ""), "'' unless defined? DESTDIR\n"
 print "  CONFIG = {}\n"
