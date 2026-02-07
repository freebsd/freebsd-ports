--- pty.c.orig	2021-12-05 10:19:53 UTC
+++ pty.c
@@ -1,6 +1,3 @@
-#define _XOPEN_SOURCE 600
-#define _DEFAULT_SOURCE
-#define _DARWIN_C_SOURCE
 #include <stdlib.h>
 #include <fcntl.h>
 #include <unistd.h>
