--- src/threads/posixthreads.c.orig	Wed May  9 12:40:39 2001
+++ src/threads/posixthreads.c	Wed Feb 20 12:37:03 2002
@@ -19,6 +19,10 @@
 extern int pthread_atfork(void (*)(void), void (*)(void), void (*)(void));
 #endif
 
+#if defined(BSD_TARGET)
+int pthread_atfork(void (*a)(void),void (*b)(void),void (*c)(void)){return -1;}
+#endif
+
 typedef int (*ptfunc)(void *);
 
 static void *RunThread(void *data) {
@@ -88,7 +92,7 @@
 }
 
 extern unsigned int Posix_SelfThread(void) {
-	return (unsigned int) pthread_self();
+	return (unsigned long)(unsigned long *) pthread_self();
 }
