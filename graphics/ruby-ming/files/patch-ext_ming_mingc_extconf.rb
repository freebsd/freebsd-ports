--- ./ext/ming/mingc/extconf.rb.orig	2012-02-20 11:14:31.882019318 -0500
+++ ./ext/ming/mingc/extconf.rb	2012-02-20 11:14:39.481020051 -0500
@@ -7,11 +7,11 @@
 dir_config('freetype')
 dir_config('ming')
 dir_config('png')
-dir_config('ungif')
+dir_config('gif')
 dir_config('z')
 
 @headers = ['ming.h'] 
-@libs =    ['freetype', 'png', 'ungif', 'z', 'ming']
+@libs =    ['freetype', 'png', 'gif', 'z', 'ming']
 @missing = {
 #  'basename' => ['char *basename(const char *path);', ['libgen.h']],
 }
