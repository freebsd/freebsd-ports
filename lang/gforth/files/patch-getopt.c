--- engine/getopt.c.orig	Sat Sep 23 20:22:09 2000
+++ engine/getopt.c	Fri Mar 16 01:42:49 2001
@@ -177,12 +177,12 @@
   REQUIRE_ORDER, PERMUTE, RETURN_IN_ORDER
 } ordering, default_ordering = PERMUTE;
 
+#include <string.h>
 #ifdef	__GNU_LIBRARY__
 /* We want to avoid inclusion of string.h with non-GNU libraries
    because there are many ways it can cause trouble.
    On some systems, it contains special magic macros that don't work
    in GCC.  */
-#include <string.h>
 #define	my_index	strchr
 #define	my_bcopy(src, dst, n)	memcpy ((dst), (src), (n))
 #else
