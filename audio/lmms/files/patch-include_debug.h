--- include/debug.h.orig	2015-03-08 02:47:14 UTC
+++ include/debug.h
@@ -30,10 +30,10 @@
 
 // set whether debug-stuff (like messages on the console, asserts and other
 // additional range-checkings) should be compiled
-
 #ifdef LMMS_DEBUG
 	#include <assert.h>
 #else
+	#undef assert
 	#define assert(x) ((void)(x))
 #endif
 #include <cstdio>
