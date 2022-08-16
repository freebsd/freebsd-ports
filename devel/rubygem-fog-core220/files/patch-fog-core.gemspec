--- fog-core.gemspec.orig	2022-08-12 11:59:03 UTC
+++ fog-core.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
     s.add_runtime_dependency(%q<builder>.freeze, [">= 0"])
     s.add_runtime_dependency(%q<mime-types>.freeze, [">= 0"])
     s.add_runtime_dependency(%q<excon>.freeze, ["~> 0.71"])
-    s.add_runtime_dependency(%q<formatador>.freeze, ["~> 0.2"])
+    s.add_runtime_dependency(%q<formatador>.freeze, [">= 0.2"])
     s.add_development_dependency(%q<tins>.freeze, [">= 0"])
     s.add_development_dependency(%q<coveralls>.freeze, [">= 0"])
     s.add_development_dependency(%q<minitest>.freeze, [">= 0"])
@@ -41,7 +41,7 @@ Gem::Specification.new do |s|
     s.add_dependency(%q<builder>.freeze, [">= 0"])
     s.add_dependency(%q<mime-types>.freeze, [">= 0"])
     s.add_dependency(%q<excon>.freeze, ["~> 0.71"])
-    s.add_dependency(%q<formatador>.freeze, ["~> 0.2"])
+    s.add_dependency(%q<formatador>.freeze, [">= 0.2"])
     s.add_dependency(%q<tins>.freeze, [">= 0"])
     s.add_dependency(%q<coveralls>.freeze, [">= 0"])
     s.add_dependency(%q<minitest>.freeze, [">= 0"])
