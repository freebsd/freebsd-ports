--- tool/mkconfig.rb.orig	2013-02-07 07:21:30.000000000 +0000
+++ tool/mkconfig.rb	2013-02-17 21:42:09.807835598 +0000
@@ -167,7 +167,8 @@
   val
 end
 vars["prefix"] = ""
-prefix = vars.expand(vars["rubyarchdir"])
+major, minor, *rest = RUBY_VERSION.split('.')
+prefix = "/lib/ruby/#{major}.#{minor}/#{arch}"
 print "  TOPDIR = File.dirname(__FILE__).chomp!(#{prefix.dump})\n"
 print "  DESTDIR = ", (drive ? "TOPDIR && TOPDIR[/\\A[a-z]:/i] || " : ""), "'' unless defined? DESTDIR\n"
 print <<'ARCH' if universal
