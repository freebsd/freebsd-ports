--- ior_rand.c.orig	2016-08-02 17:15:56 UTC
+++ ior_rand.c
@@ -24,6 +24,7 @@ static char rcsid[] = "$Header: /home/we
 #include <time.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <sys/time.h>
 
 /*
  * Solaris needs ior_mach.h to be after the above or
