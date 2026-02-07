--- pdk.gemspec.orig	2025-12-31 22:38:25 UTC
+++ pdk.gemspec
@@ -23,19 +23,19 @@ Gem::Specification.new do |s|
   s.specification_version = 4
 
   s.add_runtime_dependency(%q<ffi>.freeze, [">= 1.15.5".freeze, "< 2.0.0".freeze])
-  s.add_runtime_dependency(%q<minitar>.freeze, ["~> 0.8".freeze])
-  s.add_runtime_dependency(%q<bundler>.freeze, [">= 2.1.0".freeze, "< 3.0.0".freeze])
+  s.add_runtime_dependency(%q<minitar>.freeze, [">= 0.8".freeze])
+  s.add_runtime_dependency(%q<bundler>.freeze, [">= 2.1.0".freeze])
   s.add_runtime_dependency(%q<cri>.freeze, ["~> 2.15.11".freeze])
   s.add_runtime_dependency(%q<childprocess>.freeze, ["~> 5.0".freeze])
-  s.add_runtime_dependency(%q<hitimes>.freeze, ["= 2.0.0".freeze])
+  s.add_runtime_dependency(%q<hitimes>.freeze, [">= 2.0.0".freeze])
   s.add_runtime_dependency(%q<tty-prompt>.freeze, ["~> 0.23".freeze])
   s.add_runtime_dependency(%q<tty-spinner>.freeze, ["~> 0.9".freeze])
   s.add_runtime_dependency(%q<tty-which>.freeze, ["~> 0.5".freeze])
-  s.add_runtime_dependency(%q<json-schema>.freeze, ["~> 5.0".freeze])
-  s.add_runtime_dependency(%q<puppet-modulebuilder>.freeze, ["~> 1.0".freeze])
+  s.add_runtime_dependency(%q<json-schema>.freeze, [">= 5.0".freeze])
+  s.add_runtime_dependency(%q<puppet-modulebuilder>.freeze, [">= 1.0".freeze])
   s.add_runtime_dependency(%q<deep_merge>.freeze, ["~> 1.2.2".freeze])
   s.add_runtime_dependency(%q<diff-lcs>.freeze, [">= 1.5.0".freeze])
-  s.add_runtime_dependency(%q<pathspec>.freeze, ["~> 1.1".freeze])
-  s.add_runtime_dependency(%q<puppet_forge>.freeze, ["~> 5.0".freeze])
+  s.add_runtime_dependency(%q<pathspec>.freeze, [">= 1.1".freeze])
+  s.add_runtime_dependency(%q<puppet_forge>.freeze, [">= 5.0".freeze])
 end
 
