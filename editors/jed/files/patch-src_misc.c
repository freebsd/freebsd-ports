--- src/misc.c.orig	2009-12-14 00:12:55.000000000 -0200
+++ src/misc.c	2009-12-14 15:12:53.000000000 -0200
@@ -769,12 +769,14 @@
 
 void jed_ungetkey_wchar (SLwchar_Type wc)
 {
+#if JED_HAS_UTF8_SUPPORT
    SLuchar_Type *b, buf[JED_MAX_MULTIBYTE_SIZE];
 
    if (NULL == (b = jed_wchar_to_multibyte (wc, buf)))
      return;
    
    ungetkey_string ((char *)buf, (int)(b-buf));
+#endif
 }
 
 
