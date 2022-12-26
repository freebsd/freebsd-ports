--- pdk.gemspec.orig	2023-01-05 19:52:41 UTC
+++ pdk.gemspec
@@ -22,16 +22,16 @@ Gem::Specification.new do |s|
   s.specification_version = 4
 
   s.add_runtime_dependency(%q<bundler>.freeze, [">= 1.15.0", "< 3.0.0"])
-  s.add_runtime_dependency(%q<childprocess>.freeze, ["~> 4.0.0"])
+  s.add_runtime_dependency(%q<childprocess>.freeze, [">= 4.0.0"])
   s.add_runtime_dependency(%q<cri>.freeze, ["~> 2.10"])
-  s.add_runtime_dependency(%q<diff-lcs>.freeze, [">= 1.4.4", "< 1.5"])
+  s.add_runtime_dependency(%q<diff-lcs>.freeze, [">= 1.4.4"])
   s.add_runtime_dependency(%q<ffi>.freeze, [">= 1.9.25", "< 2.0.0"])
   s.add_runtime_dependency(%q<gettext-setup>.freeze, ["~> 0.24"])
   s.add_runtime_dependency(%q<hitimes>.freeze, ["= 2.0.0"])
-  s.add_runtime_dependency(%q<json-schema>.freeze, ["= 2.8.0"])
-  s.add_runtime_dependency(%q<json_pure>.freeze, ["~> 2.5.1"])
+  s.add_runtime_dependency(%q<json-schema>.freeze, [">= 2.8.0"])
+  s.add_runtime_dependency(%q<json_pure>.freeze, [">= 2.5.1"])
   s.add_runtime_dependency(%q<minitar>.freeze, ["~> 0.6"])
-  s.add_runtime_dependency(%q<pathspec>.freeze, ["~> 0.2.1"])
+  s.add_runtime_dependency(%q<pathspec>.freeze, [">= 0.2.1"])
   s.add_runtime_dependency(%q<tty-prompt>.freeze, ["~> 0.22"])
   s.add_runtime_dependency(%q<tty-spinner>.freeze, ["~> 0.5"])
   s.add_runtime_dependency(%q<tty-which>.freeze, ["~> 0.3"])
