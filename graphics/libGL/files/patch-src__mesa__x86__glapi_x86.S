--- ./src/mesa/x86/glapi_x86.S.orig	2009-03-13 04:28:49.000000000 +0100
+++ ./src/mesa/x86/glapi_x86.S	2011-01-28 18:11:56.000000000 +0100
@@ -47,7 +47,7 @@
 #define GL_OFFSET(x) CODEPTR(REGOFF(4 * x, EAX))
 
 #if defined(GNU_ASSEMBLER) && !defined(__DJGPP__) && !defined(__MINGW32__)
-#define GLOBL_FN(x) GLOBL x ; .type x, function
+#define GLOBL_FN(x) GLOBL x ; .type x, @function
 #else
 #define GLOBL_FN(x) GLOBL x
 #endif
