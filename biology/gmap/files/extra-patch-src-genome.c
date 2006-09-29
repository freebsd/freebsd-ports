--- src/genome.c.orig	Sun Mar  5 11:14:48 2006
+++ src/genome.c	Fri Sep 29 09:23:15 2006
@@ -15,13 +15,13 @@
 #include <stddef.h>
 #include <stdlib.h>
 #include <string.h>
-#include <sys/mman.h>		/* For munmap */
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>		/* For lseek and close */
 #endif
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h>		/* For off_t */
 #endif
+#include <sys/mman.h>		/* For munmap */
 
 #ifdef HAVE_PTHREAD
 #include <pthread.h>		/* sys/types.h already included above */
