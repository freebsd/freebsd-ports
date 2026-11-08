- workaround for:
- - https://gitlab.inria.fr/scotch/scotch/-/issues/35
- - https://github.com/FreeFem/FreeFem-sources/issues/296

--- src/libscotch/library.h.orig	2026-09-29 10:12:17 UTC
+++ src/libscotch/library.h
@@ -65,6 +65,9 @@
 #ifndef LIB_SCOTCH_H
 #define LIB_SCOTCH_H
 
+#include <sys/types.h>
+#include <stdio.h>
+
 /*
 **  The type and structure definitions.
 */
