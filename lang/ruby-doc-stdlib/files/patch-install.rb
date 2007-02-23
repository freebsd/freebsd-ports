--- install.rb.orig	Fri Aug  4 17:53:04 2006
+++ install.rb	Fri Aug  4 17:53:10 2006
@@ -125,7 +125,7 @@
           Shall I bother?
         }.trim
       end
-    elsif Dir["stdlib"] > 0
+    elsif Dir["stdlib"].size > 0
       # It's got *something* in it, but not stdlib doc.
       confirm %{
         #@doc_base/stdlib contains something, but not what I expected.
