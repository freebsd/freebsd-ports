--- nettest_unix.c.orig	Thu Nov 18 23:24:22 2004
+++ nettest_unix.c	Thu Nov 18 23:26:24 2004
@@ -52,7 +52,9 @@
 #include <string.h>
 #include <time.h>
 #include <sys/time.h>
-#if ! defined(__bsdi__) && ! defined(_APPLE_)
+#if __FreeBSD__
+#include <stdlib.h>
+#elif ! defined(__bsdi__) && ! defined(_APPLE_)
 #include <malloc.h>
 #else
 #include <sys/malloc.h>
