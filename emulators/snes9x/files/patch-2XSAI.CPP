--- 2XSAI.CPP.orig	Fri Jul 25 23:20:19 2003
+++ 2XSAI.CPP	Sat Aug  9 00:54:02 2003
@@ -81,12 +81,12 @@
 #include "port.h"
 #include "gfx.h"
 
-#if (!defined(NOASM) && defined (__i386__) || defined (__i486__) || \
-     defined (__i586__) || defined (__WIN32__) || defined (__DJGPP))
-#  ifndef MMX
-#    define MMX
-#  endif
-#endif
+//#if (!defined(NOASM) && defined (__i386__) || defined (__i486__) || \
+//     defined (__i586__) || defined (__WIN32__) || defined (__DJGPP))
+//#  ifndef MMX
+//#    define MMX
+//#  endif
+//#endif
 
 extern "C"
 {
