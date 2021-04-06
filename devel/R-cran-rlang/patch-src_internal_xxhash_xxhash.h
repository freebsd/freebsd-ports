--- src/internal/xxhash/xxhash.h.orig	2021-03-31 12:18:19 UTC
+++ src/internal/xxhash/xxhash.h
@@ -2409,6 +2409,7 @@ XXH_PUBLIC_API XXH64_hash_t XXH64_hashFromCanonical(co
 #    if defined(__GNUC__) && !defined(__APPLE_ALTIVEC__)
 #      define __APPLE_ALTIVEC__
 #    endif
+#    define vector __vector
 #    include <altivec.h>
 #  endif
 
