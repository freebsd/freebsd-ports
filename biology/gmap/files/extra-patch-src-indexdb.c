--- src/indexdb.c.orig	Sat Mar  4 10:19:53 2006
+++ src/indexdb.c	Fri Sep 29 11:12:55 2006
@@ -22,13 +22,13 @@
 #include <stdlib.h>
 #include <string.h>		/* For memset */
 #include <ctype.h>		/* For toupper */
-#include <sys/mman.h>		/* For munmap */
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>		/* For lseek and close */
 #endif
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h>		/* For off_t */
 #endif
+#include <sys/mman.h>		/* For munmap */
 
 #include "mem.h"
 #include "fopen.h"
