--- msync.c.orig	Sat Aug  6 16:14:27 2005
+++ msync.c	Sat Aug  6 16:14:45 2005
@@ -7,6 +7,7 @@
 #pragma ident	"@(#)msync.c	1.1	05/08/04 SMI"
 #endif
 
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <unistd.h>
 #include <stdlib.h>
