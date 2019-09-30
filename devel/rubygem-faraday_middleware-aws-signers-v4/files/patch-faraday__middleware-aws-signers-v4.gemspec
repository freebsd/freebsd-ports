--- faraday_middleware-aws-signers-v4.gemspec.orig	2019-09-30 21:13:09 UTC
+++ faraday_middleware-aws-signers-v4.gemspec
@@ -23,7 +23,7 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<faraday>.freeze, ["~> 0.9"])
-      s.add_runtime_dependency(%q<aws-sdk-resources>.freeze, ["~> 3.0.0.rc2"])
+      s.add_runtime_dependency(%q<aws-sdk-resources>.freeze, ["~> 3.0"])
       s.add_development_dependency(%q<bundler>.freeze, [">= 0"])
       s.add_development_dependency(%q<rake>.freeze, [">= 0"])
       s.add_development_dependency(%q<rspec>.freeze, [">= 3.0.0"])
@@ -33,7 +33,7 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<webmock>.freeze, [">= 0"])
     else
       s.add_dependency(%q<faraday>.freeze, ["~> 0.9"])
-      s.add_dependency(%q<aws-sdk-resources>.freeze, ["~> 3.0.0.rc2"])
+      s.add_dependency(%q<aws-sdk-resources>.freeze, ["~> 3.0"])
       s.add_dependency(%q<bundler>.freeze, [">= 0"])
       s.add_dependency(%q<rake>.freeze, [">= 0"])
       s.add_dependency(%q<rspec>.freeze, [">= 3.0.0"])
@@ -44,7 +44,7 @@ Gem::Specification.new do |s|
     end
   else
     s.add_dependency(%q<faraday>.freeze, ["~> 0.9"])
-    s.add_dependency(%q<aws-sdk-resources>.freeze, ["~> 3.0.0.rc2"])
+    s.add_dependency(%q<aws-sdk-resources>.freeze, ["~> 3.0"])
     s.add_dependency(%q<bundler>.freeze, [">= 0"])
     s.add_dependency(%q<rake>.freeze, [">= 0"])
     s.add_dependency(%q<rspec>.freeze, [">= 3.0.0"])
