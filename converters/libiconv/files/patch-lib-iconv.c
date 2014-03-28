--- lib/iconv.c.orig
+++ lib/iconv.c
@@ -598,7 +598,7 @@
    It wants to define the symbols 'iconv_open', 'iconv', 'iconv_close'.  */
 #define strong_alias(name, aliasname) _strong_alias(name, aliasname)
 #define _strong_alias(name, aliasname) \
-  extern __typeof (name) aliasname __attribute__ ((alias (#name)));
+  extern LIBICONV_DLL_EXPORTED __typeof (name) aliasname __attribute__ ((alias (#name)));
 #undef iconv_open
 #undef iconv
 #undef iconv_close
