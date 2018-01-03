--- mario-redis-lock.gemspec.orig	2018-01-03 01:55:48 UTC
+++ mario-redis-lock.gemspec
@@ -22,7 +22,7 @@ Gem::Specification.new do |s|
     s.specification_version = 4
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<redis>.freeze, [">= 3.0.5", "~> 3"])
+      s.add_runtime_dependency(%q<redis>.freeze, [">= 3.0.5"])
       s.add_development_dependency(%q<bundler>.freeze, ["~> 1"])
       s.add_development_dependency(%q<rake>.freeze, ["~> 10"])
     else
@@ -31,7 +31,7 @@ Gem::Specification.new do |s|
       s.add_dependency(%q<rake>.freeze, ["~> 10"])
     end
   else
-    s.add_dependency(%q<redis>.freeze, [">= 3.0.5", "~> 3"])
+    s.add_dependency(%q<redis>.freeze, [">= 3.0.5"])
     s.add_dependency(%q<bundler>.freeze, ["~> 1"])
     s.add_dependency(%q<rake>.freeze, ["~> 10"])
   end
