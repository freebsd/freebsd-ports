--- src/libs/libgroff/encoding.cc.bak	Tue Mar  4 20:26:04 2003
+++ src/libs/libgroff/encoding.cc	Tue Mar  4 21:33:16 2003
@@ -177,7 +177,8 @@
   inline wchar make_wchar(unsigned char c0, encoding_istream& eis) {
     wchar wc = 0;
     char inbuf[8], outbuf[8];
-    char *inp, *outp;
+    const char *inp;
+    char *outp;
     size_t inbytesleft, outbytesleft;
     int i = 0;
     
@@ -212,7 +213,8 @@
 
   inline int put_wchar(wchar wc, encoding_ostream& eos) {
     char inbuf[4], outbuf[4];
-    char *inp, *outp;
+    const char *inp;
+    char *outp;
     size_t inbytesleft, outbytesleft;
 
     if (!is_wchar_code(wc)) {
@@ -377,6 +379,9 @@
 #if HAVE_LANGINFO_CODESET
   locale = nl_langinfo(CODESET);
 #endif
+  if (strcmp(locale, "ja_JP.EUC") == 0 || strcmp(locale, "ja_JP.eucJP") == 0) {
+	  locale = "EUC-JP";
+  }
   select_input_encoding_handler(locale);
   select_output_encoding_handler(locale);
 #endif
