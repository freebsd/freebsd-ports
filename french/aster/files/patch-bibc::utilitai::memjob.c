--- bibc/utilitai/memjob.c.orig	Wed Apr 23 11:41:04 2003
+++ bibc/utilitai/memjob.c	Tue Jul  1 22:37:31 2003
@@ -20,9 +20,9 @@
 extern char g_memory[];
 #include <string.h>
 #include <stdio.h>
-#if defined SOLARIS || IRIX || P_LINUX || TRU64 || SOLARIS64 
-#include <sys/resource.h>
+#if defined SOLARIS || IRIX || P_LINUX || TRU64 || SOLARIS64
 #include <sys/time.h>
+#include <sys/resource.h>
    long memjob_(void)
 #elif defined HPUX
 #include <sys/resource.h>
