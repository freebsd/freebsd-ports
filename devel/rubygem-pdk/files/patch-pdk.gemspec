--- pdk.gemspec.orig	2023-03-24 21:05:49 UTC
+++ pdk.gemspec
@@ -27,10 +27,10 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<diff-lcs>.freeze, [">= 1.5.0"])
   s.add_runtime_dependency(%q<ffi>.freeze, [">= 1.15.5", "< 2.0.0"])
   s.add_runtime_dependency(%q<hitimes>.freeze, ["= 2.0.0"])
-  s.add_runtime_dependency(%q<json-schema>.freeze, ["= 2.8.0"])
+  s.add_runtime_dependency(%q<json-schema>.freeze, [">= 2.8.0"])
   s.add_runtime_dependency(%q<json_pure>.freeze, ["~> 2.6.2"])
   s.add_runtime_dependency(%q<minitar>.freeze, ["~> 0.6"])
-  s.add_runtime_dependency(%q<pathspec>.freeze, ["~> 0.2.1"])
+  s.add_runtime_dependency(%q<pathspec>.freeze, [">= 0.2.1"])
   s.add_runtime_dependency(%q<tty-prompt>.freeze, ["~> 0.23"])
   s.add_runtime_dependency(%q<tty-spinner>.freeze, ["~> 0.9"])
   s.add_runtime_dependency(%q<tty-which>.freeze, ["~> 0.5"])
