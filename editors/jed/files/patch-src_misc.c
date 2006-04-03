--- src/misc.c.orig	Mon Apr  3 09:05:53 2006
+++ src/misc.c	Mon Apr  3 09:05:05 2006
@@ -741,12 +741,14 @@
 
 void jed_ungetkey_wchar (SLwchar_Type wc)
 {
+#if JED_HAS_UTF8_SUPPORT
    SLuchar_Type *b, buf[SLUTF8_MAX_MBLEN];
 
    if (NULL == (b = jed_wchar_to_multibyte (wc, buf)))
      return;
    
    ungetkey_string ((char *)buf, (int)(b-buf));
+#endif
 }
 
 
