--- ext/goocanvas/extconf.rb.orig	2016-03-31 16:13:37 UTC
+++ ext/goocanvas/extconf.rb
@@ -31,6 +31,7 @@ rescue LoadError
 end
 
 [
+  "cairo",
   "glib2",
   "atk",
   "pango",
