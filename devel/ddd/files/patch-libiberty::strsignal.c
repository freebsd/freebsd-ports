--- libiberty/strsignal.c.orig	Wed Oct 22 14:46:55 2003
+++ libiberty/strsignal.c	Fri Feb 27 13:33:02 2004
@@ -241,6 +241,7 @@
    same name, it differs from other implementations in that it is dynamically
    initialized rather than statically initialized. */
 
+#ifndef __FreeBSD__
 #ifndef HAVE_SYS_SIGLIST
 
 static int sys_nsig;
@@ -257,6 +258,7 @@
 #endif
 extern const char * const sys_siglist[];
 
+#endif
 #endif
 
 
