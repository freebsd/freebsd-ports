--- src/include/arith.h.orig
+++ src/include/arith.h
@@ -22,7 +22,7 @@
 #ifndef __ARITH_H_INCLUDED__
 #define __ARITH_H_INCLUDED__
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 #include "gcc/arith.h"
 #elif defined(__TURBOC__)
 #include "bcc/arith.h"
