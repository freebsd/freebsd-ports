--- danger.gemspec.orig	2023-04-24 04:48:52 UTC
+++ danger.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
   s.add_runtime_dependency(%q<cork>.freeze, ["~> 0.1"])
   s.add_runtime_dependency(%q<faraday>.freeze, [">= 0.9.0", "< 3.0"])
   s.add_runtime_dependency(%q<faraday-http-cache>.freeze, ["~> 2.0"])
-  s.add_runtime_dependency(%q<git>.freeze, ["~> 1.13.0"])
+  s.add_runtime_dependency(%q<git>.freeze, ["~> 1.13"])
   s.add_runtime_dependency(%q<kramdown>.freeze, ["~> 2.3"])
   s.add_runtime_dependency(%q<kramdown-parser-gfm>.freeze, ["~> 1.0"])
   s.add_runtime_dependency(%q<no_proxy_fix>.freeze, [">= 0"])
