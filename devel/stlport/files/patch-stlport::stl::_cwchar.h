--- stlport/stl/_cwchar.h.orig	Sun Nov  2 16:59:08 2003
+++ stlport/stl/_cwchar.h	Sat Nov  6 17:01:49 2004
@@ -24,7 +24,7 @@
 #endif
 #endif
 
-# if defined (__MRC__) || defined (__SC__) || defined (__BORLANDC__) || defined(__FreeBSD__) || (defined (__GNUC__) && defined (__APPLE__) || defined( __Lynx__ )) || defined (_STLP_NO_WCHAR_T)
+# if defined (__MRC__) || defined (__SC__) || defined (__BORLANDC__) || (defined(__FreeBSD__) && !defined(_STLP_FREEBSD_HAS_WFUNCS)) || (defined (__GNUC__) && defined (__APPLE__) || defined( __Lynx__ )) || defined (_STLP_NO_WCHAR_T)
 
 #  include _STLP_NATIVE_C_HEADER(stddef.h)
 #  if defined (__FreeBSD__) || defined (__Lynx__)
