--- lib/dbi.rb.orig	2009-09-14 05:43:32.000000000 +0900
+++ lib/dbi.rb	2011-01-17 02:53:43.819024000 +0900
@@ -37,7 +37,7 @@
 
 begin
     require "rubygems"
-    gem "deprecated"
+    gem "deprecated", "<3"
 rescue LoadError
 end
 
