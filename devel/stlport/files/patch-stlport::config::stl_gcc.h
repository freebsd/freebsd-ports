--- stlport/config/stl_gcc.h.orig	Thu Jan 10 19:41:58 2002
+++ stlport/config/stl_gcc.h	Thu Jun  6 23:15:40 2002
@@ -9,8 +9,14 @@
 
 #   define _STLP_NO_MEMBER_TEMPLATE_KEYWORD
 
-# if defined(__FreeBSD__) || defined (__hpux) || defined(__amigaos__)
+# if defined (__hpux) || defined(__amigaos__)
 #  define _STLP_NO_WCHAR_T
+# elif defined(__FreeBSD__)
+# if (__FreeBSD_cc_version < 500005)
+# define _STLP_NO_WCHAR_T
+# else
+# define _STLP_FREEBSD_HAS_WFUNCS
+# endif /* __FreeBSD_cc_version < 500005 */
 # endif
 
 # if defined (__sun)
@@ -77,7 +83,7 @@
 
 # endif
 
-#if defined (__CYGWIN__) || defined (__MINGW32__) || !(defined (_STLP_USE_GLIBC) || defined (__sun)) 
+#if defined (__CYGWIN__) || defined (__MINGW32__) || !(defined (_STLP_USE_GLIBC) || defined (_STLP_FREEBSD_HAS_WFUNCS) || defined (__sun))
 #ifndef __MINGW32__
 #   define _STLP_NO_NATIVE_MBSTATE_T      1
 #endif
@@ -250,8 +256,17 @@
 
 # if (__GNUC__ >= 3)
 
+#ifdef __FreeBSD__
+#  if (__FreeBSD_cc_version > 500005)
+#    define _STLP_NATIVE_INCLUDE_PATH ../__GNUC__.__GNUC_MINOR__
+#  else
+#    define _STLP_NATIVE_INCLUDE_PATH ../g++
+#    define _STLP_NATIVE_OLD_STREAMS_INCLUDE_PATH ../g++/backward
+#  endif
+#else
 #  define _STLP_NATIVE_INCLUDE_PATH ../g++-v3
 #  define _STLP_NATIVE_OLD_STREAMS_INCLUDE_PATH ../g++-v3/backward
+#endif
 
 # elif (__GNUC_MINOR__ < 8)
 
