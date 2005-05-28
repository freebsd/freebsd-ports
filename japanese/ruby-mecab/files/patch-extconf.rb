--- extconf.rb.orig	Sun Mar 20 22:19:10 2005
+++ extconf.rb	Mon May  2 02:03:15 2005
@@ -3,7 +3,7 @@
 mecab_config = with_config('mecab-config', 'mecab-config')
 use_mecab_config = enable_config('mecab-config')
 
-`mecab-config --libs-only-l`.chomp.split.each { | lib |
+`#{mecab_config} --libs-only-l`.chomp.split.each{ | lib |
   have_library(lib)
 }
 
