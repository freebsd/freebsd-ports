--- extconf.rb.orig	Fri Dec 12 09:36:59 2003
+++ extconf.rb	Fri Dec 12 09:45:19 2003
@@ -1,12 +1,12 @@
 require 'mkmf'
 
-mecab_config = with_config ('mecab-config', 'mecab-config')
+mecab_config = with_config('mecab-config', 'mecab-config')
 use_mecab_config = enable_config('mecab-config')
 
-`mecab-config --libs-only-l`.chomp.split.each { | lib |
-  have_library (lib)
+`#{mecab_config} --libs-only-l`.chomp.split.each{ | lib |
+  have_library(lib)
 }
 
 $CFLAGS += ' ' + `#{mecab_config} --cflags`.chomp
 
-have_header ('mecab.h') && create_makefile('MeCab')
+have_header('mecab.h') && create_makefile('MeCab')
