--- src/global.hpp.orig	Tue Jun 28 17:55:19 2005
+++ src/global.hpp	Fri Feb 10 00:42:31 2006
@@ -44,7 +44,7 @@
 
 void makePace();
 
-inline int ROUND( const real x ) { return static_cast<int>( round( x )); }
+#define ROUND(x) (int)((x)-floor(x) < 0.5 ? floor(x) : ceil(x))
 
 // already defined somewhere else
 //template<class T> T min( const T a, const T b ) { return a < b ? a : b; }
