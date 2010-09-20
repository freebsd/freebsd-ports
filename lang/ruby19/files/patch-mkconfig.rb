--- mkconfig.rb.orig	2008-12-12 06:54:37.000000000 -0800
+++ mkconfig.rb	2010-09-19 17:51:43.000000000 -0700
@@ -102,7 +102,8 @@
 
 drive = File::PATH_SEPARATOR == ';'
 
-prefix = '/lib/ruby/' + RUBY_VERSION + '/' + RUBY_PLATFORM
+major, minor, *rest = RUBY_VERSION.split('.')
+prefix = '/lib/ruby/' + "#{major}.#{minor}/" + RUBY_PLATFORM
 print "  TOPDIR = File.dirname(__FILE__).chomp!(#{prefix.dump})\n"
 print "  DESTDIR = ", (drive ? "TOPDIR && TOPDIR[/\\A[a-z]:/i] || " : ""), "'' unless defined? DESTDIR\n"
 print "  CONFIG = {}\n"
@@ -140,7 +141,7 @@
 print(*v_fast)
 print(*v_others)
 print <<EOS
-  CONFIG["rubylibdir"] = "$(libdir)/$(ruby_install_name)/$(ruby_version)"
+  CONFIG["rubylibdir"] = "$(libdir)/ruby/$(ruby_version)"
   CONFIG["archdir"] = "$(rubylibdir)/$(arch)"
   CONFIG["sitelibdir"] = "$(sitedir)/$(ruby_version)"
   CONFIG["sitearchdir"] = "$(sitelibdir)/$(sitearch)"
