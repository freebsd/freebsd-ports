--- install.rb.orig	Mon Apr  8 22:09:31 2002
+++ install.rb	Sun Jun  9 02:07:03 2002
@@ -660,3 +660,7 @@
   def install_dir_ext_main( rel )
-    install_files allext('.'), config('so-dir') + '/' + rel, 0555
+    #install_files allext('.'), config('so-dir') + '/' + rel, 0555
+    command sprintf('%s sitelibdir=%s sitearchdir=%s site-install',
+		    config('make-prog'),
+		    config('rb-dir'),
+		    config('so-dir'))
   end
