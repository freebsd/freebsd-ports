--- mkconfig.rb.orig	2009-02-09 19:56:48.000000000 +0300
+++ mkconfig.rb	2009-02-09 19:59:30.000000000 +0300
@@ -140,7 +140,7 @@
 print(*v_fast)
 print(*v_others)
 print <<EOS
-  CONFIG["rubylibdir"] = "$(libdir)/$(ruby_install_name)/$(ruby_version)"
+  CONFIG["rubylibdir"] = "$(libdir)/ruby/$(ruby_version)"
   CONFIG["archdir"] = "$(rubylibdir)/$(arch)"
   CONFIG["sitelibdir"] = "$(sitedir)/$(ruby_version)"
   CONFIG["sitearchdir"] = "$(sitelibdir)/$(sitearch)"
