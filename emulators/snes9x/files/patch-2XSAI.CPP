--- 2xsai.cpp.orig	Fri Dec  5 02:03:08 2003
+++ 2xsai.cpp	Sun Jan 25 01:41:08 2004
@@ -81,7 +81,8 @@
 #include "port.h"
 #include "gfx.h"
 
-#if (defined(USE_X86_ASM) && (defined (__i386__) || defined (__i486__) || \
+#if (defined(USE_X86_ASM) && defined(ASMKREED) && \
+              (defined (__i386__) || defined (__i486__) || \
                defined (__i586__) || defined (__WIN32__) || defined (__DJGPP)))
 #  ifndef MMX
 #    define MMX
