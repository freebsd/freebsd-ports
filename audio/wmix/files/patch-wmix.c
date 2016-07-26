--- wmix.c.orig	2004-05-13 00:30:53 UTC
+++ wmix.c
@@ -24,7 +24,6 @@
 #include <string.h>
 #include <signal.h>
 #include <string.h>
-#include <getopt.h>
 #include <unistd.h>
 
 #include <X11/X.h>
@@ -134,7 +133,7 @@ int main(int argc, char **argv)
     }
 
     /* handle writing PID file, silently ignore if we can't do it */
-    pid = calloc(1, strlen(home) + 10);
+    pid = calloc(1, strlen(home) + 11);
     sprintf(pid, "%s/.wmix.pid", home);
     fp = fopen(pid, "w");
     if (fp) {
