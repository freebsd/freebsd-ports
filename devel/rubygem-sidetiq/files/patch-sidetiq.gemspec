--- sidetiq.gemspec.orig	2015-07-06 11:49:20 UTC
+++ sidetiq.gemspec
@@ -24,7 +24,7 @@ Gem::Specification.new do |s|
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<sidekiq>, [">= 3.0.0"])
       s.add_runtime_dependency(%q<celluloid>, [">= 0.14.1"])
-      s.add_runtime_dependency(%q<ice_cube>, ["= 0.11.1"])
+      s.add_runtime_dependency(%q<ice_cube>, [">= 0.11.1"])
       s.add_development_dependency(%q<rake>, [">= 0"])
       s.add_development_dependency(%q<sinatra>, [">= 0"])
       s.add_development_dependency(%q<mocha>, [">= 0"])
@@ -34,7 +34,7 @@ Gem::Specification.new do |s|
     else
       s.add_dependency(%q<sidekiq>, [">= 3.0.0"])
       s.add_dependency(%q<celluloid>, [">= 0.14.1"])
-      s.add_dependency(%q<ice_cube>, ["= 0.11.1"])
+      s.add_dependency(%q<ice_cube>, [">= 0.11.1"])
       s.add_dependency(%q<rake>, [">= 0"])
       s.add_dependency(%q<sinatra>, [">= 0"])
       s.add_dependency(%q<mocha>, [">= 0"])
@@ -45,7 +45,7 @@ Gem::Specification.new do |s|
   else
     s.add_dependency(%q<sidekiq>, [">= 3.0.0"])
     s.add_dependency(%q<celluloid>, [">= 0.14.1"])
-    s.add_dependency(%q<ice_cube>, ["= 0.11.1"])
+    s.add_dependency(%q<ice_cube>, [">= 0.11.1"])
     s.add_dependency(%q<rake>, [">= 0"])
     s.add_dependency(%q<sinatra>, [">= 0"])
     s.add_dependency(%q<mocha>, [">= 0"])
