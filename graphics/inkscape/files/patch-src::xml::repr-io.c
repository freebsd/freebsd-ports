
$FreeBSD: /tmp/pcvs/ports/graphics/inkscape/files/Attic/patch-src::xml::repr-io.c,v 1.1 2003-11-17 04:03:39 bland Exp $

--- src/xml/repr-io.c	2001/11/22 15:20:50	1.1
+++ src/xml/repr-io.c	2001/11/22 15:21:18
@@ -1,6 +1,8 @@
 #define SP_REPR_IO_C
 
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <stdio.h>
 #include "repr.h"
