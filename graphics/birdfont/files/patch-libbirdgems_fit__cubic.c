--- libbirdgems/fit_cubic.c.orig	2020-02-29 17:58:28 UTC
+++ libbirdgems/fit_cubic.c
@@ -24,6 +24,8 @@ Adapted to BirdFont by Johan Mattsson 2015
 
 #ifdef MAC
 #include <malloc/malloc.h>
+#elif __FreeBSD__
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
