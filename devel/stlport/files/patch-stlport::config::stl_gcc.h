--- stlport/config/stl_gcc.h.orig	Sun Nov  2 16:59:11 2003
+++ stlport/config/stl_gcc.h	Mon Nov 29 18:42:05 2004
@@ -7,11 +7,20 @@
 # define _STLP_USE_GLIBC
 #endif
 
+#if !defined(__FreeBSD__) || (defined(__FreeBSD__) && (__FreeBSD_cc_version < 530001))
 #   define _STLP_NO_MEMBER_TEMPLATE_KEYWORD
+#endif
+
 
-# if defined(__FreeBSD__) || defined (__hpux) || defined(__amigaos__) || ( defined(__OS2__) && defined(__EMX__) )
+#if defined (__hpux) || defined(__amigaos__) || ( defined(__OS2__) && defined(__EMX__) )
+# define _STLP_NO_WCHAR_T
+#elif defined(__FreeBSD__)
+# if (__FreeBSD_cc_version < 500005)
 #  define _STLP_NO_WCHAR_T
-# endif
+# else
+#  define _STLP_FREEBSD_HAS_WFUNCS
+# endif /* __FreeBSD_cc_version < 500005 */
+#endif
 
 #ifdef __USLC__
 # include <config/stl_sco.h>
@@ -81,7 +90,7 @@
 
 # endif
 
-#if defined (__CYGWIN__) || defined (__MINGW32__) || !(defined (_STLP_USE_GLIBC) || defined (__sun)) 
+#if defined (__CYGWIN__) || defined (__MINGW32__) || !(defined (_STLP_USE_GLIBC) || defined (_STLP_FREEBSD_HAS_WFUNCS) || defined (__sun)) 
 #ifndef __MINGW32__
 #   define _STLP_NO_NATIVE_MBSTATE_T      1
 #endif
@@ -267,7 +276,7 @@
 #   define _STLP_NATIVE_INCLUDE_PATH ../g++-v3
 #   define _STLP_NATIVE_OLD_STREAMS_INCLUDE_PATH ../g++-v3/backward
 #  else
-#   if defined(__GNUC_PATCHLEVEL__) && (__GNUC_PATCHLEVEL__ > 0)
+#   if defined(__GNUC_PATCHLEVEL__) && (__GNUC_PATCHLEVEL__ > 0) && !defined(__FreeBSD__)
 #     define _STLP_NATIVE_INCLUDE_PATH ../__GNUC__.__GNUC_MINOR__.__GNUC_PATCHLEVEL__
 #     define _STLP_NATIVE_OLD_STREAMS_INCLUDE_PATH ../__GNUC__.__GNUC_MINOR__.__GNUC_PATCHLEVEL__/backward
 #   else
