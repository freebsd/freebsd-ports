--- rm/rminit.c~	Mon Jul  8 12:53:37 2002
+++ rm/rminit.c		Mon Jul  8 12:54:51 2002
@@ -91,7 +91,9 @@
 #ifdef SOLARIS
     glXInitThreadsSUN();
 #else
+#ifndef __FreeBSD__
     pthread_setconcurrency(12);
+#endif    
 #endif
 #endif
 
