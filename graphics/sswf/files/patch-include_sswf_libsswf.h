--- include/sswf/libsswf.h.orig	2009-03-08 04:04:03 UTC
+++ include/sswf/libsswf.h
@@ -68,16 +68,6 @@ SOFTWARE.
 
 #include	"sswf/libsswf-config.h"
 
-/* wint_t is an "equivalent" to wchar_t without being limited to 16 bits as on MS-Windows */
-#ifndef _MSVC
-#ifndef __APPLE_CC__
-#ifndef _WINT_T
-#define _WINT_T
-typedef unsigned int	wint_t;
-#endif
-#endif
-#endif
-
 #ifndef	M_PI
 #define	M_PI		3.14159265358979323846
 #endif
@@ -88,7 +78,7 @@ typedef unsigned int	wint_t;
 #define	rint(x)		((double) (long) floor(x + 0.5))
 #endif
 
-#ifdef _LIBICONV_H
+#if defined(_LIBICONV_VERSION) && _LIBICONV_VERSION < 0x010B
 #define	ICONV_INPUT_CAST
 #else
 /* older versions of iconv() were broken in regard to the
