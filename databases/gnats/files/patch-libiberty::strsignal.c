--- libiberty/strsignal.c.orig	Thu Jun 27 00:33:59 2002
+++ libiberty/strsignal.c	Thu Jun 27 00:38:03 2002
@@ -241,11 +241,6 @@
 static int sys_nsig;
 static const char **sys_siglist;
 
-#else
-
-static int sys_nsig = NSIG;
-extern const char * const sys_siglist[];
-
 #endif
 
 
