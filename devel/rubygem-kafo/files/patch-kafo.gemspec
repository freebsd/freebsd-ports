--- kafo.gemspec.orig	2015-08-28 14:32:28 UTC
+++ kafo.gemspec
@@ -28,7 +28,6 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<simplecov>, ["< 0.9"])
       s.add_development_dependency(%q<ci_reporter>, ["~> 1.9.0"])
       s.add_runtime_dependency(%q<kafo_parsers>, [">= 0"])
-      s.add_runtime_dependency(%q<puppet>, ["< 4.0.0"])
       s.add_runtime_dependency(%q<logging>, ["< 3.0.0"])
       s.add_runtime_dependency(%q<clamp>, [">= 0.6.2"])
       s.add_runtime_dependency(%q<highline>, ["< 2.0", ">= 1.6.21"])
