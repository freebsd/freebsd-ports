--- libs/math/vector.h.orig	2013-06-30 22:04:34.000000000 +0800
+++ libs/math/vector.h	2013-09-06 20:03:32.000000000 +0800
@@ -45,27 +45,14 @@
 	return static_cast<__int64>( f + 0.5 );
 }
 
-#elif defined( __FreeBSD__ )
+#else // lrint is part of ISO C99
 
-inline long lrint( double f ){
-	return static_cast<long>( f + 0.5 );
-}
-
-inline long long llrint( double f ){
-	return static_cast<long long>( f + 0.5 );
-}
-
-#elif defined( __GNUC__ )
-
-// lrint is part of ISO C99
 #define _ISOC9X_SOURCE  1
 #define _ISOC99_SOURCE  1
 
 #define __USE_ISOC9X    1
 #define __USE_ISOC99    1
 
-#else
-#error "unsupported platform"
 #endif
 
 #include <cmath>
