--- nq/source/sys_unix.c.orig
+++ nq/source/sys_unix.c
@@ -69,6 +69,9 @@
        fcntl (0, F_SETFL, fcntl (0, F_GETFL, 0) & ~O_NONBLOCK);
 }
 
+extern void Key_Progs_Init (progs_t *pr);
+void (*x)() = Key_Progs_Init;
+
 int
 main (int c, const char *v[])
 {
