--- sysdeps/common/fsusage.c.orig	Thu Mar 11 15:53:36 2004
+++ sysdeps/common/fsusage.c	Thu Mar 11 15:56:37 2004
@@ -28,7 +28,7 @@
 # endif
 #endif
 #ifndef UINTMAX_MAX
-# define UINTMAX_MAX ((uintmax_t) -1)
+# define UINTMAX_MAX ((uint64_t) -1)
 #endif
 
 #include <sys/types.h>
@@ -84,7 +84,7 @@
    a uintmax_t value that is all 1 bits if X is all 1 bits, even if X
    is unsigned and narrower than uintmax_t.  */
 #define PROPAGATE_ALL_ONES(x) \
-  ((sizeof (x) < sizeof (uintmax_t) \
+  ((sizeof (x) < sizeof (uint64_t) \
     && (~ (x) == (sizeof (x) < sizeof (int) \
 		  ? - (1 << (sizeof (x) * CHAR_BIT)) \
 		  : 0))) \
@@ -92,7 +92,7 @@
 
 /* Extract the top bit of X as an uintmax_t value.  */
 #define EXTRACT_TOP_BIT(x) ((x) \
-			    & ((uintmax_t) 1 << (sizeof (x) * CHAR_BIT - 1)))
+			    & ((uint64_t) 1 << (sizeof (x) * CHAR_BIT - 1)))
 
 /* If a value is negative, many space usage primitives store it into an
    integer variable by assignment, even if the variable's type is unsigned.
