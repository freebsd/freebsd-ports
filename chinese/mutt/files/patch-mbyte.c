--- mbyte.c.orig	2016-10-09 03:35:50.000000000 +0800
+++ mbyte.c	2016-12-02 11:18:42.600658000 +0800
@@ -24,6 +24,9 @@
 # include "config.h"
 #endif
 
+/*
+ * Trad. Chinese (Big5) support by yjchou@linux.cis.nctu.edu.tw
+ */
 #include "mutt.h"
 #include "mbyte.h"
 #include "charset.h"
@@ -39,6 +42,7 @@
 int Charset_is_utf8 = 0;
 #ifndef HAVE_WC_FUNCS
 static int charset_is_ja = 0;
+static int charset_is_big5 = 0;
 static iconv_t charset_to_utf8 = (iconv_t)(-1);
 static iconv_t charset_from_utf8 = (iconv_t)(-1);
 #endif
@@ -52,6 +56,7 @@ void mutt_set_charset (char *charset)
   Charset_is_utf8 = 0;
 #ifndef HAVE_WC_FUNCS
   charset_is_ja = 0;
+  charset_is_big5 = 0;
   if (charset_to_utf8 != (iconv_t)(-1))
   {
     iconv_close (charset_to_utf8);
@@ -82,6 +87,14 @@ void mutt_set_charset (char *charset)
     charset_from_utf8 = mutt_iconv_open (charset, "utf-8", 0);
   }
 #endif
+#ifndef HAVE_WC_FUNCS
+  else if (!strcmp(buffer, "big5"))
+  {
+    charset_is_big5 = 1;
+    charset_to_utf8 = iconv_open ("UTF-8", charset);
+    charset_from_utf8 = iconv_open (charset, "UTF-8");
+  }
+#endif
 
 #if defined(HAVE_BIND_TEXTDOMAIN_CODESET) && defined(ENABLE_NLS)
   bind_textdomain_codeset(PACKAGE, buffer);
@@ -256,7 +269,7 @@ size_t mbrtowc (wchar_t *pwc, const char
 
 int iswprint (wint_t wc)
 {
-  if (Charset_is_utf8 || charset_is_ja)
+  if (Charset_is_utf8 || charset_is_ja || charset_is_big5)
     return ((0x20 <= wc && wc < 0x7f) || 0xa0 <= wc);
   else
     return (0 <= wc && wc < 256) ? IsPrint (wc) : 0;
@@ -264,7 +277,7 @@ int iswprint (wint_t wc)
 
 int iswspace (wint_t wc)
 {
-  if (Charset_is_utf8 || charset_is_ja)
+  if (Charset_is_utf8 || charset_is_ja || charset_is_big5)
     return (9 <= wc && wc <= 13) || wc == 32;
   else
     return (0 <= wc && wc < 256) ? isspace (wc) : 0;
@@ -347,7 +360,7 @@ static int iswalpha_ucs (wint_t wc)
 
 wint_t towupper (wint_t wc)
 {
-  if (Charset_is_utf8 || charset_is_ja)
+  if (Charset_is_utf8 || charset_is_ja || charset_is_big5)
     return towupper_ucs (wc);
   else
     return (0 <= wc && wc < 256) ? toupper (wc) : wc;
@@ -355,7 +368,7 @@ wint_t towupper (wint_t wc)
 
 wint_t towlower (wint_t wc)
 {
-  if (Charset_is_utf8 || charset_is_ja)
+  if (Charset_is_utf8 || charset_is_ja || charset_is_big5)
     return towlower_ucs (wc);
   else
     return (0 <= wc && wc < 256) ? tolower (wc) : wc;
@@ -363,7 +376,7 @@ wint_t towlower (wint_t wc)
 
 int iswalnum (wint_t wc)
 {
-  if (Charset_is_utf8 || charset_is_ja)
+  if (Charset_is_utf8 || charset_is_ja || charset_is_big5)
     return iswalnum_ucs (wc);
   else
     return (0 <= wc && wc < 256) ? isalnum (wc) : 0;
@@ -404,13 +417,31 @@ int wcwidth_ja (wchar_t ucs)
     return -1;
 }
 
+int wcwidth_big5(wchar_t ucs)
+{
+  return wcwidth_ja (ucs);
+}
+
 int wcwidth_ucs(wchar_t ucs);
 
 int wcwidth (wchar_t wc)
 {
   if (!Charset_is_utf8)
   {
-    if (!charset_is_ja)
+    if (charset_is_ja)
+    {
+      /* Japanese */
+      int k = wcwidth_ja (wc);
+      if (k != -1)
+	return k;
+    }
+    else if (charset_is_big5)
+    {
+      int k = wcwidth_big5 (wc);
+      if (k != -1)
+        return k;
+    }
+    else
     {
       /* 8-bit case */
       if (!wc)
@@ -420,13 +451,6 @@ int wcwidth (wchar_t wc)
       else
 	return -1;
     }
-    else
-    {
-      /* Japanese */
-      int k = wcwidth_ja (wc);
-      if (k != -1)
-	return k;
-    }
   }
   return wcwidth_ucs (wc);
 }
