--- libs/tcmalloc-1.4/src/malloc_extension.cc.orig
+++ libs/tcmalloc-1.4/src/malloc_extension.cc
@@ -57,6 +57,7 @@
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
+#include <pthread.h>
 #if defined HAVE_STDINT_H
 #include <stdint.h>
 #elif defined HAVE_INTTYPES_H
