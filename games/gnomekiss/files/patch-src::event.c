--- src/event.c.orig	Sat May 10 07:14:55 2003
+++ src/event.c	Sat May 10 11:05:13 2003
@@ -21,6 +21,7 @@
 #endif
 
 #include <sys/types.h>
+#include <signal.h>
 #include <sys/wait.h>
 #include <unistd.h>
 #include <gnome.h>
