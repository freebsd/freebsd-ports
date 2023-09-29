--- src/lib/grd3-write.c.orig	2023-09-29 18:20:02 UTC
+++ src/lib/grd3-write.c
@@ -4,6 +4,8 @@
 
 #include "cptutils/grd3-write.h"
 
+#include <sys/types.h>
+
 #if defined HAVE_ENDIAN_H
 #include <endian.h>
 #elif defined HAVE_SYS_ENDIAN_H
