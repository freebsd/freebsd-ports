--- src/SDL/i_system.c.orig	2008-11-09 18:19:11 UTC
+++ src/SDL/i_system.c
@@ -72,6 +72,7 @@
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <errno.h>
+#include <sys/cpuset.h>
 
 #ifndef PRBOOM_SERVER
 #include "m_argv.h"
@@ -441,7 +442,7 @@ void I_SetAffinityMask(void)
     // POSIX version:
     int i;
     {
-      cpu_set_t set;
+      cpuset_t set;
 
       CPU_ZERO(&set);
 
