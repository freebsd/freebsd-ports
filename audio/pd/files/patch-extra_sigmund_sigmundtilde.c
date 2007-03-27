--- extra/sigmund~/sigmund~.c.orig	Sun Mar 25 12:22:47 2007
+++ extra/sigmund~/sigmund~.c	Sun Mar 25 12:22:50 2007
@@ -16,7 +16,7 @@
 #ifdef MSW
 #include <malloc.h>
 #else
-#include <alloca.h>
+//#include <alloca.h>
 #endif
 #include <stdlib.h>
 #ifdef NT
