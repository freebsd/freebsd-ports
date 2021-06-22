--- pg_query.gemspec.orig	2021-06-20 06:58:25 UTC
+++ pg_query.gemspec
@@ -29,20 +29,20 @@ Gem::Specification.new do |s|
       s.add_development_dependency(%q<rspec>.freeze, ["~> 3.0"])
       s.add_development_dependency(%q<rubocop>.freeze, ["= 0.49.1"])
       s.add_development_dependency(%q<rubocop-rspec>.freeze, ["= 1.15.1"])
-      s.add_runtime_dependency(%q<google-protobuf>.freeze, ["~> 3.15.5"])
+      s.add_runtime_dependency(%q<google-protobuf>.freeze, [">= 3.17.1"])
     else
       s.add_dependency(%q<rake-compiler>.freeze, ["~> 0"])
       s.add_dependency(%q<rspec>.freeze, ["~> 3.0"])
       s.add_dependency(%q<rubocop>.freeze, ["= 0.49.1"])
       s.add_dependency(%q<rubocop-rspec>.freeze, ["= 1.15.1"])
-      s.add_dependency(%q<google-protobuf>.freeze, ["~> 3.15.5"])
+      s.add_dependency(%q<google-protobuf>.freeze, [">= 3.17.1"])
     end
   else
     s.add_dependency(%q<rake-compiler>.freeze, ["~> 0"])
     s.add_dependency(%q<rspec>.freeze, ["~> 3.0"])
     s.add_dependency(%q<rubocop>.freeze, ["= 0.49.1"])
     s.add_dependency(%q<rubocop-rspec>.freeze, ["= 1.15.1"])
-    s.add_dependency(%q<google-protobuf>.freeze, ["~> 3.15.5"])
+    s.add_dependency(%q<google-protobuf>.freeze, [">= 3.17.1"])
   end
 end
 
