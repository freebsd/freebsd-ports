--- ./http-md5.cxx.orig	2012-12-22 12:42:25.000000000 +0100
+++ ./http-md5.cxx	2012-12-22 12:42:28.000000000 +0100
@@ -120,7 +120,7 @@
 {
   int		i;				/* Looping var */
   char		*md5ptr;			/* Pointer into MD5 string */
-  static char	*hex = "0123456789abcdef";	/* Hex digits */
+  static char const *hex = "0123456789abcdef";	/* Hex digits */
 
 
  /*
