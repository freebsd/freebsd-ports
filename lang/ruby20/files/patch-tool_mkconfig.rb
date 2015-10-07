--- tool/mkconfig.rb.orig	2013-05-27 03:20:04 UTC
+++ tool/mkconfig.rb
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
