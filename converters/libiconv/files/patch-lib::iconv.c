
$FreeBSD$

--- lib/iconv.c.orig	Sat May 26 03:25:09 2001
+++ lib/iconv.c	Sun Mar 17 15:47:32 2002
@@ -176,6 +176,13 @@
 }
 #endif
 
+#undef libiconv_open
+
+iconv_t libiconv_open (const char* tocode, const char* fromcode)
+{
+  return (iconv_open(tocode, fromcode));
+}
+
 iconv_t iconv_open (const char* tocode, const char* fromcode)
 {
   struct conv_struct * cd;
@@ -358,6 +365,15 @@
   return (iconv_t)(-1);
 }
 
+#undef libiconv
+
+size_t libiconv (iconv_t icd,
+		 ICONV_CONST char* * inbuf, size_t *inbytesleft,
+		 char* * outbuf, size_t *outbytesleft)
+{
+  return (iconv(icd, inbuf, inbytesleft, outbuf, outbytesleft));
+}
+
 size_t iconv (iconv_t icd,
               ICONV_CONST char* * inbuf, size_t *inbytesleft,
               char* * outbuf, size_t *outbytesleft)
@@ -371,6 +387,13 @@
                                    outbuf,outbytesleft);
 }
 
+#undef libiconv_close
+
+int libiconv_close (iconv_t icd)
+{
+  return (iconv_close(icd));
+}
+
 int iconv_close (iconv_t icd)
 {
   conv_t cd = (conv_t) icd;
@@ -378,7 +401,7 @@
   return 0;
 }
 
-#ifndef LIBICONV_PLUG
+#if !defined(LIBICONV_PLUG) || defined(__FreeBSD__)
 
 int iconvctl (iconv_t icd, int request, void* argument)
 {
