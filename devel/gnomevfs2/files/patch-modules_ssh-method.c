--- modules/ssh-method.c.orig	Mon Jun 10 13:28:42 2002
+++ modules/ssh-method.c	Mon Jun 10 13:28:51 2002
@@ -34,6 +34,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <signal.h>
 #include <unistd.h>
 
 typedef struct {
