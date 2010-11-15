--- ./lib/misc/hostinfoPosix.c.orig	2010-04-28 03:17:27.000000000 +0900
+++ ./lib/misc/hostinfoPosix.c	2010-11-11 22:37:23.000000000 +0900
@@ -31,7 +31,6 @@
 #include <sys/wait.h>
 #include <signal.h>
 #include <sys/time.h>
-#include <sys/timeb.h>
 #include <pwd.h>
 #include <pthread.h>
 #include <sys/resource.h>
