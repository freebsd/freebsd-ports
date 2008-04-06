--- mkconfig.rb.orig	2007-12-28 02:40:14.000000000 +0300
+++ mkconfig.rb	2007-12-28 02:40:25.000000000 +0300
@@ -138,7 +138,7 @@
 print(*v_fast)
 print(*v_others)
 print <<EOS
-  CONFIG["ruby_version"] = "$(MAJOR).$(MINOR).$(TEENY)"
+  CONFIG["ruby_version"] = "$(MAJOR).$(MINOR)"
   CONFIG["rubylibdir"] = "$(libdir)/ruby/$(ruby_version)"
   CONFIG["archdir"] = "$(rubylibdir)/$(arch)"
   CONFIG["sitelibdir"] = "$(sitedir)/$(ruby_version)"
