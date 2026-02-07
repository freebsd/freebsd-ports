--- src/include/memmode.h.orig
+++ src/include/memmode.h
@@ -19,7 +19,7 @@
 #ifndef  __MEMMODE_H_INCLUDED__
 #define  __MEMMODE_H_INCLUDED__
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 #include "gcc/memmode.h"
 #elif defined(__TURBOC__)
 #include "bcc/memmode.h"
