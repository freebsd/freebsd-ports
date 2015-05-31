--- couchrest.gemspec.orig	2015-05-31 17:14:31 UTC
+++ couchrest.gemspec
@@ -23,7 +23,7 @@ Gem::Specification.new do |s|
     s.specification_version = 3
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<rest-client>, ["~> 1.6.1"])
+      s.add_runtime_dependency(%q<rest-client>, [">= 1.6.1"])
       s.add_runtime_dependency(%q<mime-types>, ["~> 1.15"])
       s.add_runtime_dependency(%q<multi_json>, ["~> 1.0"])
       s.add_development_dependency(%q<json>, [">= 1.7.0"])
