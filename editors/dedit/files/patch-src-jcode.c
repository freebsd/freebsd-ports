--- src/jcode.c.orig	2000-10-13 08:45:02.000000000 +0200
+++ src/jcode.c	2007-11-04 00:49:09.000000000 +0100
@@ -251,7 +251,7 @@
 char *
 kanji_conv_auto(char *str, const char *dstset)
 {
-    unsigned char *buf, *ret;
+    char *buf, *ret;
     iconv_t cd;
     size_t insize = 0;
     size_t outsize = 0;
@@ -278,7 +278,7 @@
         break;
     }
     
-    buf = (unsigned char *)malloc(strlen(str)* 4 + 1);
+    buf = malloc(strlen(str)* 4 + 1);
     if(!buf)
         return NULL;
     
@@ -315,7 +315,6 @@
 {
    static char *jpcode = NULL;
    static char *locale_euc[]  = { JCODE_LOCALE_EUC, NULL };
-   static char *locale_jis[]  = { JCODE_LOCALE_JIS, NULL };
    static char *locale_sjis[] = { JCODE_LOCALE_SJIS, NULL };
 
    static struct LOCALE_TABLE {
@@ -352,7 +351,7 @@
 char *
 kanji_conv(char *str, const char *dstset, const char *srcset)
 {
-    unsigned char *buf, *ret;
+    char *buf, *ret;
     iconv_t cd;
     size_t insize = 0;
     size_t outsize = 0;
@@ -363,7 +362,7 @@
     if(!str)
         return NULL;
     
-    buf = (unsigned char *)malloc(strlen(str) * 4 + 1);
+    buf = malloc(strlen(str) * 4 + 1);
     if(!buf)
         return NULL;
     
