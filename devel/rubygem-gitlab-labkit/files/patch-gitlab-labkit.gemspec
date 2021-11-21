--- gitlab-labkit.gemspec.orig	2021-11-22 11:14:49 UTC
+++ gitlab-labkit.gemspec
@@ -24,7 +24,7 @@ Gem::Specification.new do |s|
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<actionpack>.freeze, [">= 5.0.0", "< 7.0.0"])
       s.add_runtime_dependency(%q<activesupport>.freeze, [">= 5.0.0", "< 7.0.0"])
-      s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.30"])
+      s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.42.0.pre1"])
       s.add_runtime_dependency(%q<jaeger-client>.freeze, ["~> 1.1"])
       s.add_runtime_dependency(%q<opentracing>.freeze, ["~> 0.4"])
       s.add_runtime_dependency(%q<pg_query>.freeze, ["~> 2.1"])
@@ -47,7 +47,7 @@ Gem::Specification.new do |s|
     else
       s.add_dependency(%q<actionpack>.freeze, [">= 5.0.0", "< 7.0.0"])
       s.add_dependency(%q<activesupport>.freeze, [">= 5.0.0", "< 7.0.0"])
-      s.add_dependency(%q<grpc>.freeze, ["~> 1.30"])
+      s.add_dependency(%q<grpc>.freeze, ["~> 1.42.0.pre1"])
       s.add_dependency(%q<jaeger-client>.freeze, ["~> 1.1"])
       s.add_dependency(%q<opentracing>.freeze, ["~> 0.4"])
       s.add_dependency(%q<pg_query>.freeze, ["~> 2.1"])
@@ -71,7 +71,7 @@ Gem::Specification.new do |s|
   else
     s.add_dependency(%q<actionpack>.freeze, [">= 5.0.0", "< 7.0.0"])
     s.add_dependency(%q<activesupport>.freeze, [">= 5.0.0", "< 7.0.0"])
-    s.add_dependency(%q<grpc>.freeze, ["~> 1.30"])
+    s.add_dependency(%q<grpc>.freeze, ["~> 1.42.0.pre1"])
     s.add_dependency(%q<jaeger-client>.freeze, ["~> 1.1"])
     s.add_dependency(%q<opentracing>.freeze, ["~> 0.4"])
     s.add_dependency(%q<pg_query>.freeze, ["~> 2.1"])
