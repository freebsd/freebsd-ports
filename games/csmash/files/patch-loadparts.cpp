--- loadparts.cpp.orig	Wed May  4 19:19:33 2005
+++ loadparts.cpp	Fri May  6 11:11:49 2005
@@ -69,8 +69,7 @@
     return a <= x && x <= b;
 }
 
-template <typename T>
-inline const T& clamp(const T& a, const T& x, const T& b) {
+inline const long clamp(long a, long x, long b) {
     if (a > x) return a;
     elif (b < x) return b;
     else return x;
