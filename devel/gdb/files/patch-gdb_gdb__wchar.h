--- gdb/gdb_wchar.h.orig  2017-09-14 09:28:17 UTC
+++ gdb/gdb_wchar.h
@@ -59,7 +59,7 @@
    iconvlist.  */
 #if defined (HAVE_ICONV) && defined (HAVE_BTOWC) \
   && (defined (__STDC_ISO_10646__) \
-      || (defined (_LIBICONV_VERSION) && _LIBICONV_VERSION >= 0x108))
+      || (!defined (LIBICONV_PLUG) && defined (_LIBICONV_VERSION) && _LIBICONV_VERSION >= 0x108))
 
 typedef wchar_t gdb_wchar_t;
 typedef wint_t gdb_wint_t;
@@ -82,7 +82,7 @@ typedef wint_t gdb_wint_t;
 #define INTERMEDIATE_ENCODING intermediate_encoding ()
 const char *intermediate_encoding (void);
 
-#elif defined (_LIBICONV_VERSION) && _LIBICONV_VERSION >= 0x108
+#elif !defined (LIBICONV_PLUG) && defined (_LIBICONV_VERSION) && _LIBICONV_VERSION >= 0x108
 #define INTERMEDIATE_ENCODING "wchar_t"
 #else
 /* This shouldn't happen, because the earlier #if should have filtered
