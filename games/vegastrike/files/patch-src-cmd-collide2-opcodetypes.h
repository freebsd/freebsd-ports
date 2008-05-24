--- src/cmd/collide2/opcodetypes.h.orig	2008-04-24 16:12:20.000000000 +0400
+++ src/cmd/collide2/opcodetypes.h	2008-05-05 23:57:08.000000000 +0400
@@ -198,13 +198,13 @@
 #include <wctype.h>
 #endif
 #if !defined(CS_HAVE_WCHAR_T) && !defined(_WCHAR_T_DEFINED)
-typedef uint16 wchar_t;
+//typedef uint16 wchar_t;
 #define _WCHAR_T_DEFINED
 #define CS_WCHAR_T_SIZE 2
 #endif
 #if !defined(CS_HAVE_WINT_T) && !defined(_WCTYPE_T_DEFINED) && \
     !defined(_WINT_T)
-typedef wchar_t wint_t;
+//typedef wchar_t wint_t;
 #define _WCTYPE_T_DEFINED
 #define _WINT_T
 #endif
