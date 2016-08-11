--- config.m4.orig	2016-06-21 11:11:59 UTC
+++ config.m4
@@ -65,6 +65,7 @@ yes
 #endif
     ],[
       PHP_PCRE_REGEX=pecl
+      PHP_ADD_INCLUDE($PHP_PCRE_DIR/include)
     ],[
       PHP_PCRE_REGEX=no
     ])
