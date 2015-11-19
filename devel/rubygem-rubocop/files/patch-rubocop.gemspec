--- rubocop.gemspec.orig	2015-11-15 16:14:30 UTC
+++ rubocop.gemspec
@@ -29,7 +29,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<powerpack>, ["~> 0.1"])
       s.add_runtime_dependency(%q<astrolabe>, ["~> 1.3"])
       s.add_runtime_dependency(%q<ruby-progressbar>, ["~> 1.7"])
-      s.add_runtime_dependency(%q<tins>, ["<= 1.6.0"])
+      s.add_runtime_dependency(%q<tins>)
       s.add_development_dependency(%q<rake>, ["~> 10.1"])
       s.add_development_dependency(%q<rspec>, ["~> 3.3.0"])
       s.add_development_dependency(%q<yard>, ["~> 0.8"])
