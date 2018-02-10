--- paperclip.gemspec.orig	2018-02-04 12:45:39 UTC
+++ paperclip.gemspec
@@ -26,7 +26,7 @@ Gem::Specification.new do |s|
     if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
       s.add_runtime_dependency(%q<activemodel>.freeze, [">= 4.2.0"])
       s.add_runtime_dependency(%q<activesupport>.freeze, [">= 4.2.0"])
-      s.add_runtime_dependency(%q<cocaine>.freeze, ["~> 0.5.5"])
+      s.add_runtime_dependency(%q<cocaine>.freeze, [">= 0.5.5"])
       s.add_runtime_dependency(%q<mime-types>.freeze, [">= 0"])
       s.add_runtime_dependency(%q<mimemagic>.freeze, ["~> 0.3.0"])
       s.add_development_dependency(%q<activerecord>.freeze, [">= 4.2.0"])
