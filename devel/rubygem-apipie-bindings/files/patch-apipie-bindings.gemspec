--- apipie-bindings.gemspec.orig	2015-05-31 16:30:52 UTC
+++ apipie-bindings.gemspec
@@ -25,7 +25,7 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<json>, [">= 1.2.1"])
-      s.add_runtime_dependency(%q<rest-client>, ["< 1.8.0", ">= 1.6.5"])
+      s.add_runtime_dependency(%q<rest-client>, [">= 1.6.5"])
       s.add_runtime_dependency(%q<oauth>, [">= 0"])
       s.add_runtime_dependency(%q<awesome_print>, [">= 0"])
       s.add_development_dependency(%q<rake>, ["~> 10.1.0"])
