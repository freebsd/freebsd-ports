--- src/utilities.h.orig	2009-01-22 06:17:01.000000000 +0800
+++ src/utilities.h	2009-02-05 08:07:44.000000000 +0800
@@ -72,7 +72,7 @@
 #if defined(HAVE_LIB_UNWIND)
 # define STACKTRACE_H "stacktrace_libunwind-inl.h"
 #elif !defined(NO_FRAME_POINTER)
-# if defined(__i386__) && __GNUC__ >= 2
+# if (defined(__i386__) || defined(__amd64__)) && __GNUC__ >= 2
 #  define STACKTRACE_H "stacktrace_x86-inl.h"
 # elif defined(__x86_64__) && __GNUC__ >= 2
 #  define STACKTRACE_H "stacktrace_x86_64-inl.h"
