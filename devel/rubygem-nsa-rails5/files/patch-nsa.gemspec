--- nsa.gemspec.orig	2018-01-05 18:00:57 UTC
+++ nsa.gemspec
@@ -24,7 +24,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<activesupport>.freeze, ["< 6", ">= 4.2"])
       s.add_runtime_dependency(%q<concurrent-ruby>.freeze, ["~> 1.0.0"])
       s.add_runtime_dependency(%q<sidekiq>.freeze, [">= 3.5.0"])
-      s.add_runtime_dependency(%q<statsd-ruby>.freeze, ["~> 1.2.0"])
+      s.add_runtime_dependency(%q<statsd-ruby>.freeze, [">= 1.2.0"])
       s.add_development_dependency(%q<bundler>.freeze, ["~> 1.10"])
       s.add_development_dependency(%q<rake>.freeze, ["~> 10.0"])
       s.add_development_dependency(%q<minitest>.freeze, [">= 0"])
