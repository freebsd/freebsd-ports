--- libiberty/strsignal.c.orig	Sun Nov  3 21:38:47 2002
+++ libiberty/strsignal.c	Sun Nov  3 21:39:31 2002
@@ -244,7 +244,7 @@
 #else
 
 #ifdef NSIG
-static int sys_nsig = NSIG;
+static __const int sys_nsig = NSIG;
 #else
 #ifdef _NSIG
 static int sys_nsig = _NSIG;
