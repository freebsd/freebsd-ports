--- libiberty/strsignal.c.orig	Thu Aug 19 20:58:24 2004
+++ libiberty/strsignal.c	Thu Aug 19 20:59:24 2004
@@ -241,6 +241,7 @@
    same name, it differs from other implementations in that it is dynamically
    initialized rather than statically initialized. */
 
+#ifndef __FreeBSD__
 #ifndef HAVE_SYS_SIGLIST
 
 static int sys_nsig;
@@ -258,7 +259,7 @@
 extern const char * const sys_siglist[];
 
 #endif
-
+#endif
 
 /*
 
