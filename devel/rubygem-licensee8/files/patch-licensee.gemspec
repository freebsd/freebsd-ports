--- licensee.gemspec.orig	2020-04-14 06:08:22 UTC
+++ licensee.gemspec
@@ -23,7 +23,7 @@ Gem::Specification.new do |s|
     s.specification_version = 4
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<rugged>.freeze, ["~> 0.24"])
+      s.add_runtime_dependency(%q<rugged>.freeze, ["~> 1.0"])
       s.add_development_dependency(%q<pry>.freeze, ["~> 0.9"])
       s.add_development_dependency(%q<rspec>.freeze, ["~> 3.5"])
       s.add_development_dependency(%q<rake>.freeze, ["~> 10.3"])
