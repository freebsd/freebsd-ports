--- compiler/txx.h.orig	Thu Dec 21 12:01:13 2000
+++ compiler/txx.h	Sat Mar 31 02:50:51 2001
@@ -17,8 +17,12 @@
 #define ulong   unsigned long
 
 #ifdef __FreeBSD__
- #ifdef i386
+ #ifdef __i386__
   #define HOST32
+  #define NL_IS_LF
+ #endif
+ #ifdef __alpha__
+  #define HOST64
   #define NL_IS_LF
  #endif
 #endif
