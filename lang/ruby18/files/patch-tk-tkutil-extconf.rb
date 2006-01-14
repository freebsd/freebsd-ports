--- ext/tk/tkutil/extconf.rb.orig	Wed Nov  2 12:19:30 2005
+++ ext/tk/tkutil/extconf.rb	Sat Jan 14 16:21:55 2006
@@ -1,4 +1,2 @@
-if compiled?('tk')
   require 'mkmf'
   create_makefile('tkutil')
-end
