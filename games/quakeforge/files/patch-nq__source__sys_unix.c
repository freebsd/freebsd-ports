--- ./nq/source/sys_unix.c.orig	Wed Jan 15 12:31:28 2003
+++ ./nq/source/sys_unix.c	Sun Dec 17 15:50:06 2006
@@ -69,6 +69,9 @@
 	fcntl (0, F_SETFL, fcntl (0, F_GETFL, 0) & ~O_NONBLOCK);
 }
 
+extern void Key_Progs_Init (progs_t *pr);
+void (*x)() = Key_Progs_Init;
+
 int
 main (int c, const char *v[])
 {
