--- ./src/lpeg/lptypes.h.orig	2014-05-19 04:42:14.000000000 -0400
+++ ./src/lpeg/lptypes.h	2014-06-04 12:40:26.924305800 -0400
@@ -9,7 +9,7 @@
 #define lptypes_h
 
 
-#if !defined(LPEG_DEBUG)
+#if !defined(LPEG_DEBUG) && !defined(NDEBUG)
 #define NDEBUG
 #endif
 
