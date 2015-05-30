--- kafo.gemspec.orig	2015-05-28 20:33:29 UTC
+++ kafo.gemspec
@@ -28,10 +28,9 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<simplecov>, ["< 0.9"])
       s.add_development_dependency(%q<ci_reporter>, ["~> 1.9.0"])
       s.add_runtime_dependency(%q<kafo_parsers>, [">= 0"])
-      s.add_runtime_dependency(%q<puppet>, ["< 4.0.0"])
       s.add_runtime_dependency(%q<logging>, ["< 2.0.0"])
       s.add_runtime_dependency(%q<clamp>, [">= 0.6.2"])
-      s.add_runtime_dependency(%q<highline>, ["< 1.7", ">= 1.6.21"])
+      s.add_runtime_dependency(%q<highline>, [">= 1.6.21"])
       s.add_runtime_dependency(%q<powerbar>, [">= 0"])
     else
       s.add_dependency(%q<bundler>, ["~> 1.3"])
