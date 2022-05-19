--- src/fpu/fpu_instructions_longdouble.h.orig	2022-05-19 07:43:50 UTC
+++ src/fpu/fpu_instructions_longdouble.h
@@ -22,7 +22,7 @@
 #ifdef __GNUC__
 # if defined(__MINGW32__) || (defined(MACOSX) && !defined(__arm64__))
 #  include "fpu_control_x86.h"
-# elif defined(ANDROID) || defined(__ANDROID__) || (defined(MACOSX) && defined(__arm64__)) || defined(EMSCRIPTEN)
+# elif defined(ANDROID) || defined(__ANDROID__) || (defined(MACOSX) && defined(__arm64__)) || defined(EMSCRIPTEN) || defined(__powerpc__)
 /* ? */
 #  define _FPU_SETCW(x) /* dummy */
 # else
