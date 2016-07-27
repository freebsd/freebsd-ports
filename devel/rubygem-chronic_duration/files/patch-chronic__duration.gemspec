--- chronic_duration.gemspec.orig	2016-07-27 10:38:00 UTC
+++ chronic_duration.gemspec
@@ -22,7 +22,7 @@ Gem::Specification.new do |s|
     s.specification_version = 4
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
-      s.add_runtime_dependency(%q<numerizer>.freeze, ["~> 0.1.1"])
+      s.add_runtime_dependency(%q<numerizer>.freeze, [">= 0.1.1"])
       s.add_development_dependency(%q<rake>.freeze, ["~> 10.0.3"])
       s.add_development_dependency(%q<rspec>.freeze, ["~> 2.12.0"])
     else
