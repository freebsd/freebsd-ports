--- libiberty/strsignal.c.orig	Mon May 29 13:45:32 2000
+++ libiberty/strsignal.c	Wed Dec 11 21:04:43 2002
@@ -247,7 +247,7 @@
 #else
 
 #ifdef NSIG
-static int sys_nsig = NSIG;
+static const int sys_nsig = NSIG;
 #else
 #ifdef _NSIG
 static int sys_nsig = _NSIG;
