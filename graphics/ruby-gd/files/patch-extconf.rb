--- extconf.rb.orig	Wed May 30 23:14:17 2001
+++ extconf.rb	Sun Jul  6 00:14:20 2003
@@ -48,7 +48,7 @@
 end
 
 if have_library('z') and have_library('png') and 
-    have_library('gd', 'gdImagePng') and have_library('m')
+    have_library('%%GD%%', 'gdImagePng') and have_library('m')
 
   if with_config('ttf') and not have_func('gdImageStringTTF')
     delete_link('ttf')
