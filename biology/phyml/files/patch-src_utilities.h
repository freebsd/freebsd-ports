--- src/utilities.h.orig	2022-04-08 15:01:10 UTC
+++ src/utilities.h
@@ -31,8 +31,8 @@ the GNU public licence. See http://www.opensource.org 
 #include <assert.h>
 #include <stdbool.h>
 #include <signal.h>
-/* #include <malloc/malloc.h> */
-/* #include <malloc.h> */
+/* #include <malloc/stdlib.h> */
+/* #include <stdlib.h> */
 
 #if (defined(__AVX__) || defined(__AVX2__))
 #include <xmmintrin.h>
