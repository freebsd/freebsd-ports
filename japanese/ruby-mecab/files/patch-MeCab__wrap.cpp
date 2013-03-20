--- MeCab_wrap.cpp.orig	2013-01-25 14:07:27.000000000 +0900
+++ MeCab_wrap.cpp	2013-03-20 15:01:31.000000000 +0900
@@ -1856,8 +1856,7 @@
 
 /* Workaround for ruby1.9.x */
 #if defined SWIGRUBY
-#include "ruby/version.h"
-#if RUBY_API_VERSION_CODE >= 10900
+#if HAVE_RUBY_ENCODING_H
 #include "ruby/encoding.h"
 #define rb_str_new rb_external_str_new
 #endif
