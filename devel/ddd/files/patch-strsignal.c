--- libiberty/strsignal.c.orig	Wed Sep  4 12:32:03 2002
+++ libiberty/strsignal.c	Wed Sep  4 12:32:52 2002
@@ -236,6 +236,7 @@
    same name, it differs from other implementations in that it is dynamically
    initialized rather than statically initialized. */
 
+#ifndef __FreeBSD__
 #ifndef HAVE_SYS_SIGLIST
 
 static int sys_nsig;
@@ -252,6 +253,7 @@
 #endif
 extern const char * const sys_siglist[];
 
+#endif
 #endif
 
