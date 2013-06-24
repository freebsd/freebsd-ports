--- config.m4.orig	2009-04-09 16:16:30.000000000 +0200
+++ config.m4	2009-04-09 16:17:02.000000000 +0200
@@ -65,6 +65,7 @@
 #endif
     ],[
       PHP_PCRE_REGEX=pecl
+      PHP_ADD_INCLUDE($PHP_PCRE_DIR/include)
     ],[
       PHP_PCRE_REGEX=no
     ])
