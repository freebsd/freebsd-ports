--- puppet-modulebuilder.gemspec.orig	2024-09-14 17:43:35 UTC
+++ puppet-modulebuilder.gemspec
@@ -22,6 +22,6 @@ Gem::Specification.new do |s|
   s.specification_version = 4
 
   s.add_runtime_dependency(%q<minitar>.freeze, ["~> 0.9".freeze])
-  s.add_runtime_dependency(%q<pathspec>.freeze, [">= 0.2.1".freeze, "< 2.0.0".freeze])
+  s.add_runtime_dependency(%q<pathspec>.freeze, [">= 0.2.1".freeze, "< 3.0.0".freeze])
 end
 
