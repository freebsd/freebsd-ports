--- src/input.c.orig	2020-10-05 19:47:54 UTC
+++ src/input.c
@@ -45,7 +45,7 @@
 #include <stdlib.h>
 #include <errno.h>
 #if HAVE_SYS_TERMIOS_H
-#include <sys/termios.h>
+#include <termios.h>
 #endif
 
 static	jmp_buf	env;		/* setjmp/longjmp buffer */
