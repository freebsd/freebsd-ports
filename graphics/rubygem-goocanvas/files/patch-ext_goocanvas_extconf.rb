--- ext/goocanvas/extconf.rb.orig	2016-01-19 22:58:55 UTC
+++ ext/goocanvas/extconf.rb
@@ -31,6 +31,7 @@ rescue LoadError
 end
 
 [
+  "cairo",
   "glib2",
   "atk",
   "pango",
