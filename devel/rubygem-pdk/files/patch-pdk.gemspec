--- pdk.gemspec.orig	2024-11-05 06:09:16 UTC
+++ pdk.gemspec
@@ -27,15 +27,15 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<bundler>.freeze, [">= 2.1.0".freeze, "< 3.0.0".freeze])
   s.add_runtime_dependency(%q<cri>.freeze, ["~> 2.15.11".freeze])
   s.add_runtime_dependency(%q<childprocess>.freeze, ["~> 5.0".freeze])
-  s.add_runtime_dependency(%q<hitimes>.freeze, ["= 2.0.0".freeze])
+  s.add_runtime_dependency(%q<hitimes>.freeze, [">= 2.0.0".freeze])
   s.add_runtime_dependency(%q<tty-prompt>.freeze, ["~> 0.23".freeze])
   s.add_runtime_dependency(%q<tty-spinner>.freeze, ["~> 0.9".freeze])
   s.add_runtime_dependency(%q<tty-which>.freeze, ["~> 0.5".freeze])
-  s.add_runtime_dependency(%q<json-schema>.freeze, ["~> 4.0".freeze])
-  s.add_runtime_dependency(%q<puppet-modulebuilder>.freeze, ["~> 1.0".freeze])
+  s.add_runtime_dependency(%q<json-schema>.freeze, [">= 4.0".freeze])
+  s.add_runtime_dependency(%q<puppet-modulebuilder>.freeze, [">= 1.0".freeze])
   s.add_runtime_dependency(%q<deep_merge>.freeze, ["~> 1.2.2".freeze])
   s.add_runtime_dependency(%q<diff-lcs>.freeze, [">= 1.5.0".freeze])
-  s.add_runtime_dependency(%q<json_pure>.freeze, ["~> 2.6.3".freeze])
-  s.add_runtime_dependency(%q<pathspec>.freeze, ["~> 1.1".freeze])
+  s.add_runtime_dependency(%q<json_pure>.freeze, [">= 2.6.3".freeze])
+  s.add_runtime_dependency(%q<pathspec>.freeze, [">= 1.1".freeze])
 end
 
