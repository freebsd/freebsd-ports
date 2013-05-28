--- tool/mkconfig.rb.orig	2013-05-27 03:20:03.501815638 +0000
+++ tool/mkconfig.rb	2013-05-27 03:20:31.093814303 +0000
@@ -173,7 +173,8 @@
 end
 vars["prefix"] = ""
 vars["exec_prefix"] = ""
-prefix = vars.expand(vars["rubyarchdir"])
+major, minor, *rest = RUBY_VERSION.split('.')
+prefix = "/lib/ruby/#{major}.#{minor}/#{arch}"
 print "  TOPDIR = File.dirname(__FILE__).chomp!(#{prefix.dump})\n"
 print "  DESTDIR = ", (drive ? "TOPDIR && TOPDIR[/\\A[a-z]:/i] || " : ""), "'' unless defined? DESTDIR\n"
 print <<'ARCH' if universal
