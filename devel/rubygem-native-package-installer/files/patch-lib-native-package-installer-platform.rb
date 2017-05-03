--- lib/native-package-installer/platform.rb.orig	2017-04-27 16:20:10 UTC
+++ lib/native-package-installer/platform.rb
@@ -33,6 +33,7 @@ class NativePackageInstaller
   end
 end
 
+require "native-package-installer/platform/freebsd"
 require "native-package-installer/platform/debian"
 require "native-package-installer/platform/fedora"
 require "native-package-installer/platform/redhat"
