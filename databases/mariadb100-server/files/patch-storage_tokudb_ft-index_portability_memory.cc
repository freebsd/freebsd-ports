--- storage/tokudb/ft-index/portability/memory.cc.orig	2015-06-17 14:54:13 UTC
+++ storage/tokudb/ft-index/portability/memory.cc
@@ -94,11 +94,6 @@ PATENT RIGHTS GRANT:
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
-#if defined(HAVE_MALLOC_H)
-# include <malloc.h>
-#elif defined(HAVE_SYS_MALLOC_H)
-# include <sys/malloc.h>
-#endif
 #include <dlfcn.h>
 #include <toku_race_tools.h>
 #include "memory.h"
