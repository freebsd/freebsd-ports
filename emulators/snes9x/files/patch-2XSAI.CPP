--- 2XSAI.CPP.orig	Sun Oct 19 22:52:14 2003
+++ 2XSAI.CPP	Sun Oct 19 22:52:56 2003
@@ -81,8 +81,9 @@
 #include "port.h"
 #include "gfx.h"
 
-#if (!defined(NOASM) && defined (__i386__) || defined (__i486__) || \
-     defined (__i586__) || defined (__WIN32__) || defined (__DJGPP))
+#if (!defined(NOASM) && !defined (__FreeBSD__) && defined (__i386__) || \
+     defined (__i486__) || defined (__i586__) || defined (__WIN32__) || \
+     defined (__DJGPP))
 #  ifndef MMX
 #    define MMX
 #  endif
