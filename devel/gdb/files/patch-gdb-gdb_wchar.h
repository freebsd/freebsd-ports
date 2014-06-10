--- gdb/gdb_wchar.h.orig	2014-06-05 10:44:18.914279516 +0200
+++ gdb/gdb_wchar.h	2014-06-05 10:46:07.264279306 +0200
@@ -56,7 +56,7 @@
    iconvlist.  */
 #if defined (HAVE_ICONV) && defined (HAVE_WCHAR_H) && defined (HAVE_BTOWC) \
   && (defined (__STDC_ISO_10646__) \
-      || (defined (_LIBICONV_VERSION) && _LIBICONV_VERSION >= 0x108))
+      || (!defined (LIBICONV_PLUG) && defined (_LIBICONV_VERSION) && _LIBICONV_VERSION >= 0x108))
 
 #include <wchar.h>
 #include <wctype.h>
@@ -82,7 +82,7 @@
 #define INTERMEDIATE_ENCODING intermediate_encoding ()
 const char *intermediate_encoding (void);
 
-#elif defined (_LIBICONV_VERSION) && _LIBICONV_VERSION >= 0x108
+#elif !defined (LIBICONV_PLUG) && defined (_LIBICONV_VERSION) && _LIBICONV_VERSION >= 0x108
 #define INTERMEDIATE_ENCODING "wchar_t"
 #else
 /* This shouldn't happen, because the earlier #if should have filtered
