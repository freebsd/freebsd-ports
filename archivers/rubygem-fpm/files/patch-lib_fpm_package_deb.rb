--- lib/fpm/package/deb.rb.orig	2019-12-03 14:42:58 UTC
+++ lib/fpm/package/deb.rb
@@ -3,7 +3,6 @@ require "fpm/namespace"
 require "fpm/package"
 require "fpm/errors"
 require "fpm/util"
-require "backports"
 require "fileutils"
 require "digest"
 
