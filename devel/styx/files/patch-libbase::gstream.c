--- libbase/gstream.c.orig	Tue Apr 17 01:04:58 2001
+++ libbase/gstream.c	Tue Apr 17 01:05:13 2001
@@ -485,7 +485,7 @@
 
 
 #else
-#if !defined(MSDOS) && ( !defined(HAVE_CONFIG_H) || defined(HAVE_ICONV_H) )
+#if defined(__FreeBSD__) || (!defined(MSDOS) && ( !defined(HAVE_CONFIG_H) || defined(HAVE_ICONV_H) ) )
 
 ConcreteType(CDIConv_T) // ICONV conversion description type
 {
