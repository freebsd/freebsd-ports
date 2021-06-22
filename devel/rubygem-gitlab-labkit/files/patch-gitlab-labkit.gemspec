--- gitlab-labkit.gemspec.orig	2021-06-20 07:05:41 UTC
+++ gitlab-labkit.gemspec
@@ -27,7 +27,7 @@ Gem::Specification.new do |s|
       s.add_runtime_dependency(%q<grpc>.freeze, ["~> 1.19"])
       s.add_runtime_dependency(%q<jaeger-client>.freeze, ["~> 1.1"])
       s.add_runtime_dependency(%q<opentracing>.freeze, ["~> 0.4"])
-      s.add_runtime_dependency(%q<gitlab-pg_query>.freeze, ["~> 2.0"])
+      s.add_runtime_dependency(%q<pg_query>.freeze, ["~> 2.0"])
       s.add_runtime_dependency(%q<redis>.freeze, ["> 3.0.0", "< 5.0.0"])
       s.add_development_dependency(%q<excon>.freeze, ["~> 0.78.1"])
       s.add_development_dependency(%q<faraday>.freeze, ["~> 1.2.0"])
@@ -49,7 +49,7 @@ Gem::Specification.new do |s|
       s.add_dependency(%q<grpc>.freeze, ["~> 1.19"])
       s.add_dependency(%q<jaeger-client>.freeze, ["~> 1.1"])
       s.add_dependency(%q<opentracing>.freeze, ["~> 0.4"])
-      s.add_dependency(%q<gitlab-pg_query>.freeze, ["~> 2.0"])
+      s.add_dependency(%q<pg_query>.freeze, ["~> 2.0"])
       s.add_dependency(%q<redis>.freeze, ["> 3.0.0", "< 5.0.0"])
       s.add_dependency(%q<excon>.freeze, ["~> 0.78.1"])
       s.add_dependency(%q<faraday>.freeze, ["~> 1.2.0"])
@@ -72,7 +72,7 @@ Gem::Specification.new do |s|
     s.add_dependency(%q<grpc>.freeze, ["~> 1.19"])
     s.add_dependency(%q<jaeger-client>.freeze, ["~> 1.1"])
     s.add_dependency(%q<opentracing>.freeze, ["~> 0.4"])
-    s.add_dependency(%q<gitlab-pg_query>.freeze, ["~> 2.0"])
+    s.add_dependency(%q<pg_query>.freeze, ["~> 2.0"])
     s.add_dependency(%q<redis>.freeze, ["> 3.0.0", "< 5.0.0"])
     s.add_dependency(%q<excon>.freeze, ["~> 0.78.1"])
     s.add_dependency(%q<faraday>.freeze, ["~> 1.2.0"])
