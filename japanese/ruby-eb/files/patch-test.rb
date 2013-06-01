--- test.rb.orig	2004-07-12 17:46:01.000000000 +0000
+++ test.rb	2013-06-01 16:52:38.058629738 +0000
@@ -1,8 +1,13 @@
 #!/bin/env ruby -Ke
+# -*- coding: euc-jp -*-
 require "eb"
-
-if $KCODE!="EUC" then
-  raise RuntimeError,"lib eb requires EUC coding system"
+ 
+if defined? Encoding
+  Encoding.default_internal = "UTF-8"
+else
+  if $KCODE!="EUC" then
+    raise RuntimeError,"lib eb requires EUC coding system"
+  end
 end
 
 b=EB::Book.new
