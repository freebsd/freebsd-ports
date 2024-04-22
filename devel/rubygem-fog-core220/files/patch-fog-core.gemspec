--- fog-core.gemspec.orig	2024-02-27 16:51:36 UTC
+++ fog-core.gemspec
@@ -24,7 +24,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<builder>.freeze, [">= 0".freeze])
   s.add_runtime_dependency(%q<mime-types>.freeze, [">= 0".freeze])
   s.add_runtime_dependency(%q<excon>.freeze, ["~> 0.71".freeze])
-  s.add_runtime_dependency(%q<formatador>.freeze, ["~> 0.2".freeze])
+  s.add_runtime_dependency(%q<formatador>.freeze, [">= 0.2".freeze])
   s.add_development_dependency(%q<tins>.freeze, [">= 0".freeze])
   s.add_development_dependency(%q<coveralls>.freeze, [">= 0".freeze])
   s.add_development_dependency(%q<minitest>.freeze, [">= 0".freeze])
