--- libiberty/strsignal.c.orig	Sat Oct 25 06:10:58 2003
+++ libiberty/strsignal.c	Sat Oct 25 06:13:09 2003
@@ -244,7 +244,7 @@
 #else
 
 #ifdef NSIG
-static int sys_nsig = NSIG;
+static __const int sys_nsig = NSIG;
 #else
 #ifdef _NSIG
 static int sys_nsig = _NSIG;
