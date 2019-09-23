--- pdk.gemspec.orig	2019-09-22 19:33:51 UTC
+++ pdk.gemspec
@@ -24,21 +24,21 @@ Gem::Specification.new do |s|
 
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<bundler>.freeze, [">= 1.15.0", "< 3.0.0"])
-      s.add_runtime_dependency(%q<childprocess>.freeze, ["~> 0.7.1"])
+      s.add_runtime_dependency(%q<childprocess>.freeze, [">= 0.7.1"])
       s.add_runtime_dependency(%q<cri>.freeze, ["~> 2.10"])
       s.add_runtime_dependency(%q<diff-lcs>.freeze, ["= 1.3"])
-      s.add_runtime_dependency(%q<ffi>.freeze, ["~> 1.9.0"])
+      s.add_runtime_dependency(%q<ffi>.freeze, [">= 1.9.0"])
       s.add_runtime_dependency(%q<gettext-setup>.freeze, ["~> 0.24"])
-      s.add_runtime_dependency(%q<hitimes>.freeze, ["= 1.3.0"])
-      s.add_runtime_dependency(%q<json-schema>.freeze, ["= 2.8.0"])
+      s.add_runtime_dependency(%q<hitimes>.freeze, [">= 1.3.0"])
+      s.add_runtime_dependency(%q<json-schema>.freeze, [">= 2.8.0"])
       s.add_runtime_dependency(%q<json_pure>.freeze, ["~> 2.1.0"])
-      s.add_runtime_dependency(%q<minitar>.freeze, ["~> 0.6.1"])
-      s.add_runtime_dependency(%q<pathspec>.freeze, ["~> 0.2.1"])
+      s.add_runtime_dependency(%q<minitar>.freeze, [">= 0.6.1"])
+      s.add_runtime_dependency(%q<pathspec>.freeze, [">= 0.2.1"])
       s.add_runtime_dependency(%q<tty-prompt>.freeze, ["~> 0.13"])
       s.add_runtime_dependency(%q<tty-spinner>.freeze, ["~> 0.5"])
       s.add_runtime_dependency(%q<tty-which>.freeze, ["~> 0.3"])
       s.add_runtime_dependency(%q<concurrent-ruby>.freeze, ["~> 1.1.5"])
-      s.add_runtime_dependency(%q<facter>.freeze, ["~> 2.5.1"])
+      s.add_runtime_dependency(%q<facter>.freeze, [">= 2.5.1"])
       s.add_runtime_dependency(%q<httpclient>.freeze, ["~> 2.8.3"])
       s.add_runtime_dependency(%q<deep_merge>.freeze, ["~> 1.1"])
     else
