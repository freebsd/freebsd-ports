--- src/threads.c.orig	2009-04-23 15:01:01 UTC
+++ src/threads.c
@@ -13,7 +13,7 @@
 #include <winbase.h> /* system services headers */
 #endif
 
-#if defined(SunOS) || defined(Irix) || defined(Linux) || defined(_CRAY) || defined(__osf__) || defined(AIX)
+#if defined(SunOS) || defined(Irix) || defined(Linux) || defined(Bsd) || defined(_CRAY) || defined(__osf__) || defined(AIX)
 #include<unistd.h>  /* sysconf() headers, used by most systems */
 #endif
 
