--- libiberty/strsignal.c.old	Wed May 19 15:05:20 2004
+++ libiberty/strsignal.c	Wed May 19 15:05:32 2004
@@ -235,7 +235,6 @@
 
 #else
 
-static int sys_nsig = NSIG;
 extern const char * const sys_siglist[];
 
 #endif
