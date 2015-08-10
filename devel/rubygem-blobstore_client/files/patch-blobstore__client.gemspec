--- blobstore_client.gemspec.orig	2015-08-10 18:41:21 UTC
+++ blobstore_client.gemspec
@@ -24,8 +24,8 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<aws-sdk>, ["= 1.60.2"])
-      s.add_runtime_dependency(%q<fog>, ["~> 1.27.0"])
-      s.add_runtime_dependency(%q<httpclient>, ["= 2.4.0"])
+      s.add_runtime_dependency(%q<fog>, ["~> 1.27"])
+      s.add_runtime_dependency(%q<httpclient>, [">= 2.4.0"])
       s.add_runtime_dependency(%q<multi_json>, ["~> 1.1"])
       s.add_runtime_dependency(%q<ruby-atmos-pure>, ["~> 1.0.5"])
       s.add_runtime_dependency(%q<bosh_common>, ["~> 1.2941.0"])
