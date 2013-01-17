--- IexMath/IexMathFpu.cpp.orig	2012-07-26 20:51:55.000000000 +0200
+++ IexMath/IexMathFpu.cpp	2012-11-01 12:00:36.000000000 +0100
@@ -27,7 +27,7 @@
 #endif
 
 
-#ifdef HAVE_UCONTEXT_H
+#if defined(HAVE_UCONTEXT_H) && (defined(x86_64) || defined(i386_))
 
 
 #include <ucontext.h>
