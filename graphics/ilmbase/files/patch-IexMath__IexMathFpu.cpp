--- ./IexMath/IexMathFpu.cpp.orig	2013-06-18 21:51:38.000000000 +0200
+++ ./IexMath/IexMathFpu.cpp	2014-01-29 13:16:44.000000000 +0100
@@ -53,7 +53,7 @@
 #endif
 
 
-#ifdef HAVE_UCONTEXT_H
+#if defined(HAVE_UCONTEXT_H) && (defined(x86_64) || defined(i386_))
 
 
 #include <ucontext.h>
