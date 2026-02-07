--- extra/pd~/pd~.c.orig	2016-04-13 23:39:44 UTC
+++ extra/pd~/pd~.c
@@ -19,6 +19,7 @@ typedef int socklen_t;
 #include <stdlib.h>
 #include <errno.h>
 #include <ctype.h>
+#include <signal.h>
 #include <sys/wait.h>
 #include <fcntl.h>
 #endif
