--- extra/pd~/pd~.c.orig	2010-07-29 05:55:17.000000000 +0900
+++ extra/pd~/pd~.c	2011-04-06 19:18:20.000000000 +0900
@@ -11,6 +11,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #include <ctype.h>
+#include <signal.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
