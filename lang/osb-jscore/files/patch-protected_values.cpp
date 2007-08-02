--- kjs/protected_values.cpp.orig	2007-08-02 14:45:26.000000000 +0200
+++ kjs/protected_values.cpp	2007-08-02 14:45:49.000000000 +0200
@@ -192,7 +192,7 @@
 template <> static inline unsigned hash<4>(ValueImp *pointer) 
 {
   int a = (int)PHI;
-  int b = (int)pointer;
+  intptr_t b = (intptr_t)pointer;
   int c = 0;
 
   a -= b; a -= c; a ^= (c>>13);
