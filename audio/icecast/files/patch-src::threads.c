--- src/threads.c.old	Mon Jul 31 14:52:19 2000
+++ src/threads.c	Mon Nov 18 12:19:41 2002
@@ -39,7 +39,10 @@
 #include <errno.h>
 #include <sys/types.h>
 #include <time.h>
+
+#define __XSI_VISIBLE 1
 #include <signal.h>
+#undef __XSI_VISIBLE
 
 #ifdef HAVE_UNISTD_H
 #include <unistd.h>
