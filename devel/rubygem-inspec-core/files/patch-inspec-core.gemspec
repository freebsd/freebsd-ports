--- inspec-core.gemspec.orig	2020-12-19 14:32:09 UTC
+++ inspec-core.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<thor>.freeze, [">= 0.20", "< 2.0"])
       s.add_runtime_dependency(%q<method_source>.freeze, [">= 0.8", "< 2.0"])
       s.add_runtime_dependency(%q<rubyzip>.freeze, ["~> 1.2", ">= 1.2.2"])
-      s.add_runtime_dependency(%q<rspec>.freeze, ["~> 3.9.0"])
+      s.add_runtime_dependency(%q<rspec>.freeze, ["~> 3.10.0"])
       s.add_runtime_dependency(%q<rspec-its>.freeze, ["~> 1.2"])
       s.add_runtime_dependency(%q<pry>.freeze, ["~> 0.13"])
       s.add_runtime_dependency(%q<hashie>.freeze, ["~> 3.4"])
@@ -37,7 +37,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<faraday>.freeze, [">= 0.9.0", "< 1.1"])
       s.add_runtime_dependency(%q<tty-table>.freeze, ["~> 0.10"])
       s.add_runtime_dependency(%q<tty-prompt>.freeze, ["~> 0.17"])
-      s.add_runtime_dependency(%q<tomlrb>.freeze, ["~> 1.2.0"])
+      s.add_runtime_dependency(%q<tomlrb>.freeze, ["~> 1.3.0"])
       s.add_runtime_dependency(%q<addressable>.freeze, ["~> 2.4"])
       s.add_runtime_dependency(%q<parslet>.freeze, ["~> 1.5"])
       s.add_runtime_dependency(%q<semverse>.freeze, ["~> 3.0"])
