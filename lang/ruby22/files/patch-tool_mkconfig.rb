--- tool/mkconfig.rb.orig	2014-07-07 10:07:01.000000000 +0800
+++ tool/mkconfig.rb	2014-12-28 03:22:15.377490192 +0800
@@ -167,8 +167,9 @@
   val.replace(newval) unless newval == val
   val
 end
-prefix = vars.expand(vars["prefix"] ||= "")
-rubyarchdir = vars.expand(vars["rubyarchdir"] ||= "")
+prefix = vars.expand(vars["rubyarchdir"])
+major, minor, *rest = RUBY_VERSION.split('.')
+rubyarchdir = "/lib/ruby/#{major}.#{minor}/#{arch}"
 relative_archdir = rubyarchdir.rindex(prefix, 0) ? rubyarchdir[prefix.size..-1] : rubyarchdir
 print "  TOPDIR = File.dirname(__FILE__).chomp!(#{relative_archdir.dump})\n"
 print "  DESTDIR = ", (drive ? "TOPDIR && TOPDIR[/\\A[a-z]:/i] || " : ""), "'' unless defined? DESTDIR\n"
