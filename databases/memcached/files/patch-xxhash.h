--- xxhash.h.orig	2022-08-26 03:34:25 UTC
+++ xxhash.h
@@ -2931,6 +2931,7 @@ enum XXH_VECTOR_TYPE /* fake enum */ {
 #    if defined(__GNUC__) && !defined(__APPLE_ALTIVEC__)
 #      define __APPLE_ALTIVEC__
 #    endif
+#    define vector __vector
 #    include <altivec.h>
 #  endif
 
