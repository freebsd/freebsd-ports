--- src/Standard/Standard_MMgrOpt.cxx.orig	2014-04-29 11:40:41.000000000 +0200
+++ src/Standard/Standard_MMgrOpt.cxx	2014-05-04 14:44:24.000000000 +0200
@@ -42,7 +42,7 @@
 # endif
 #endif
 #ifdef HAVE_MALLOC_H
-# include <malloc.h>
+# include <stdlib.h>
 #endif
 #include <stdlib.h>
 #include <sys/types.h>
