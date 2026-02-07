--- ./pipex_posix.c.orig	2014-01-11 04:44:58.000000000 +0100
+++ ./pipex_posix.c	2014-01-11 04:45:23.000000000 +0100
@@ -2,11 +2,12 @@
 
 // includes
 
+#include <sys/wait.h>
 #include <string.h>
 #include <stdlib.h>
 #include <errno.h>
 #include <wordexp.h>
-#include <sys/wait.h>
+#include <signal.h>
 #include "pipex.h"
 
 // prototypes
