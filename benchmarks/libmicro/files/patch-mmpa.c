--- mmap.c.orig	Sat Aug  6 16:13:46 2005
+++ mmap.c	Sat Aug  6 16:14:01 2005
@@ -7,6 +7,7 @@
 #pragma ident	"@(#)mmap.c	1.6	05/08/04 SMI"
 #endif
 
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <unistd.h>
 #include <stdlib.h>
