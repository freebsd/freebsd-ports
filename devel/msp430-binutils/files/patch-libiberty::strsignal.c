--- libiberty/strsignal.c.orig	Sun Feb 23 16:01:05 2003
+++ libiberty/strsignal.c	Sun Feb 23 16:01:16 2003
@@ -247,7 +247,7 @@
 #else
 
 #ifdef NSIG
-static int sys_nsig = NSIG;
+static __const int sys_nsig = NSIG;
 #else
 #ifdef _NSIG
 static int sys_nsig = _NSIG;
