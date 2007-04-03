--- ext/tk/tkutil/extconf.rb.orig	Tue Apr  3 21:08:12 2007
+++ ext/tk/tkutil/extconf.rb	Tue Apr  3 21:08:16 2007
@@ -5,7 +5,5 @@
   has_tk = true
 end
 
-if has_tk
   require 'mkmf'
   create_makefile('tkutil')
-end
