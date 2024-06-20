--- pdk.gemspec.orig	2024-06-12 01:08:10 UTC
+++ pdk.gemspec
@@ -27,11 +27,11 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<cri>.freeze, ["~> 2.15.11".freeze])
   s.add_runtime_dependency(%q<diff-lcs>.freeze, [">= 1.5.0".freeze])
   s.add_runtime_dependency(%q<ffi>.freeze, [">= 1.15.5".freeze, "< 2.0.0".freeze])
-  s.add_runtime_dependency(%q<hitimes>.freeze, ["= 2.0.0".freeze])
-  s.add_runtime_dependency(%q<json_pure>.freeze, ["~> 2.6.3".freeze])
+  s.add_runtime_dependency(%q<hitimes>.freeze, [">= 2.0.0".freeze, "< 4.0.0".freeze])
+  s.add_runtime_dependency(%q<json_pure>.freeze, [">= 2.6.3".freeze])
   s.add_runtime_dependency(%q<json-schema>.freeze, ["~> 4.0".freeze])
   s.add_runtime_dependency(%q<minitar>.freeze, ["~> 0.8".freeze])
-  s.add_runtime_dependency(%q<pathspec>.freeze, ["~> 1.1".freeze])
+  s.add_runtime_dependency(%q<pathspec>.freeze, [">= 1.1".freeze])
   s.add_runtime_dependency(%q<tty-prompt>.freeze, ["~> 0.23".freeze])
   s.add_runtime_dependency(%q<tty-spinner>.freeze, ["~> 0.9".freeze])
   s.add_runtime_dependency(%q<tty-which>.freeze, ["~> 0.5".freeze])
