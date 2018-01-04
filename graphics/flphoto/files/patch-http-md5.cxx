--- http-md5.cxx.orig	2005-01-23 03:52:44 UTC
+++ http-md5.cxx
@@ -120,7 +120,7 @@ HTTP::md5_string(const MD5Byte *sum,		/*
 {
   int		i;				/* Looping var */
   char		*md5ptr;			/* Pointer into MD5 string */
-  static char	*hex = "0123456789abcdef";	/* Hex digits */
+  static char const *hex = "0123456789abcdef";	/* Hex digits */
 
 
  /*
