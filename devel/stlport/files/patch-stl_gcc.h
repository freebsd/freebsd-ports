--- ../stlport/config/stl_gcc.h.orig	Thu Jul 13 18:53:26 2000
+++ ../stlport/config/stl_gcc.h	Thu May 17 00:35:52 2001
@@ -14,7 +14,9 @@
 #   define __STL_HAS_NO_NEW_C_HEADERS     1
 
+#if 0
 # if defined(__FreeBSD__)
 #  define __STL_NO_WCHAR_T
 # endif
+#endif
 
 # if defined(__MINGW32__)
