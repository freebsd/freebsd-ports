- workaround for:
- - https://gitlab.inria.fr/scotch/scotch/-/issues/35
- - https://github.com/FreeFem/FreeFem-sources/issues/296

--- src/libscotch/library.h.orig	2017-02-22 07:20:57 UTC
+++ src/libscotch/library.h
@@ -61,6 +61,9 @@
 #ifndef SCOTCH_H
 #define SCOTCH_H
 
+#include <sys/types.h>
+#include <stdio.h>
+
 /*
 **  The type and structure definitions.
 */
