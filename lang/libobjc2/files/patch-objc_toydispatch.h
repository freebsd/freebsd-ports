--- objc/toydispatch.h.orig	2015-08-07 11:33:41 UTC
+++ objc/toydispatch.h
@@ -14,7 +14,7 @@
 #if !defined(__has_include)
 #define __has_include(x) 0
 #endif
-#if __has_include(<dispatch/dispatch.h>) && !defined(__TOY_DISPATCH__)
+#if __has_include(<no-dispatch/dispatch.h>) && !defined(__TOY_DISPATCH__)
 #	include <dispatch/dispatch.h>
 #else
 
