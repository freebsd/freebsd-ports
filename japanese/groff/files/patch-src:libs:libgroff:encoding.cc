--- src/libs/libgroff/encoding.cc.bak	Wed Sep 10 03:45:14 2003
+++ src/libs/libgroff/encoding.cc	Wed Sep 10 11:31:11 2003
@@ -179,7 +179,8 @@
   inline wchar make_wchar(unsigned char c0, encoding_istream& eis) {
     wchar wc = 0;
     char inbuf[8], outbuf[8];
-    char *inp, *outp;
+    const char *inp;
+    char *outp;
     size_t inbytesleft, outbytesleft;
     int i = 0;
     
@@ -214,7 +215,8 @@
 
   inline int put_wchar(wchar wc, encoding_ostream& eos) {
     char inbuf[4], outbuf[4];
-    char *inp, *outp;
+    const char *inp;
+    char *outp;
     size_t inbytesleft, outbytesleft;
 
     if (!is_wchar_code(wc)) {
@@ -382,6 +384,9 @@
 #if HAVE_LANGINFO_CODESET
   charset = nl_langinfo(CODESET);
 #else
+  if (strcmp(locale, "ja_JP.EUC") == 0) {
+    locale = "ja_JP.eucJP";
+  }
   charset = strchr(locale, '.');
   if (charset)
     ++charset;
