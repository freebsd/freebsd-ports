--- simgear/misc/sha1.c.orig	2016-05-25 05:08:11.559005375 +0000
+++ simgear/misc/sha1.c	2016-05-25 05:39:02.947268577 +0000
@@ -6,25 +6,26 @@
 //#include <stdint.h>
 //#include <string.h>
 
+#if defined(__FreeBSD__)
+# include <machine/endian.h>
+#else
+# if !defined(_WIN32)
+#  include <endian.h>
+# endif
+#endif
 
 #ifdef __BIG_ENDIAN__
 # define SHA_BIG_ENDIAN
-#elif defined __LITTLE_ENDIAN__
-/* override */
 #elif defined __BYTE_ORDER
 # if __BYTE_ORDER__ ==  __ORDER_BIG_ENDIAN__
 # define SHA_BIG_ENDIAN
 # endif
-#elif defined _WIN32
-/* assume little-endian, there is no endian.h on MSVC */
-#else // ! defined __LITTLE_ENDIAN__
-# include <endian.h> // machine/endian.h
-# if __BYTE_ORDER__ ==  __ORDER_BIG_ENDIAN__
-#  define SHA_BIG_ENDIAN
+#elif defined BYTE_ORDER
+# if BYTE_ORDER == BIG_ENDIAN
+# define SHA_BIG_ENDIAN
 # endif
 #endif
 
-
 /* code */
 #define SHA1_K0  0x5a827999
 #define SHA1_K20 0x6ed9eba1
