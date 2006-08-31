--- include/sswf/libsswf.h.orig	Sat Aug 12 23:59:53 2006
+++ include/sswf/libsswf.h	Sun Aug 13 00:00:44 2006
@@ -60,16 +60,6 @@
 
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
