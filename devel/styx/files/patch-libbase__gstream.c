--- libbase/gstream.c.orig	2003-12-09 15:37:07 UTC
+++ libbase/gstream.c
@@ -497,7 +497,7 @@ void GS_fprint_ucs4(FILE* fp, wc_string 
 
 
 #else
-#if !defined(MSDOS) && ( !defined(HAVE_CONFIG_H) || defined(HAVE_ICONV_H) )
+#if defined(__FreeBSD__) || (!defined(MSDOS) && ( !defined(HAVE_CONFIG_H) || defined(HAVE_ICONV_H) ) )
 
 ConcreteType(CDIConv_T) // ICONV conversion description type
 {
