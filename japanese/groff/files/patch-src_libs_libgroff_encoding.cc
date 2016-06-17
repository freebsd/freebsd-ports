--- src/libs/libgroff/encoding.cc.bak	Wed Sep 10 03:45:14 2003
+++ src/libs/libgroff/encoding.cc	Wed Sep 10 11:31:11 2003
@@ -382,6 +382,9 @@
 #if HAVE_LANGINFO_CODESET
   charset = nl_langinfo(CODESET);
 #else
+  if (strcmp(locale, "ja_JP.EUC") == 0) {
+    locale = "ja_JP.eucJP";
+  }
   charset = strchr(locale, '.');
   if (charset)
     ++charset;
