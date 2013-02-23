--- tool/mkconfig.rb.orig	2013-01-15 07:03:47.000000000 +0000
+++ tool/mkconfig.rb	2013-02-12 03:29:09.829833511 +0000
@@ -148,7 +148,8 @@
 
 drive = File::PATH_SEPARATOR == ';'
 
-prefix = "/#{v_runtime[:libdir] || 'lib'}/ruby/#{version}/#{arch}"
+major, minor, *rest = RUBY_VERSION.split('.')
+prefix = "/lib/ruby/#{major}.#{minor}/#{arch}"
 print "  TOPDIR = File.dirname(__FILE__).chomp!(#{prefix.dump})\n"
 print "  DESTDIR = ", (drive ? "TOPDIR && TOPDIR[/\\A[a-z]:/i] || " : ""), "'' unless defined? DESTDIR\n"
 print <<'ARCH' if universal
