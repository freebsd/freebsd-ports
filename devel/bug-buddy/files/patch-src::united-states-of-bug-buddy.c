--- src/united-states-of-bug-buddy.c.orig	Tue Nov 30 18:21:10 2004
+++ src/united-states-of-bug-buddy.c	Tue Nov 30 18:21:15 2004
@@ -36,6 +36,7 @@
 #include <sys/types.h>
 #include <sysexits.h>
 #include <sys/wait.h>
+#include <signal.h>
 
 #if 0
 static char *help_pages[] = {
