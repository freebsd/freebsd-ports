--- sv_sys_unix.c.orig	Tue Jun  3 17:53:55 2003
+++ sv_sys_unix.c	Tue Jun  3 17:59:41 2003
@@ -24,7 +24,7 @@
 #include <libc.h>
 #endif
 
-#if defined(__linux__) || defined(sun) || defined(__GNUC__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(sun) || defined(__GNUC__)
 #include <sys/stat.h>
 #include <unistd.h>
 #include <sys/time.h>
@@ -364,7 +364,7 @@
 =============
 */
 
-void main (int argc, char *argv[])
+int main (int argc, char *argv[])
 {
 	double			time, oldtime, newtime;
 	quakeparms_t	parms;
@@ -444,5 +444,6 @@
 			usleep (sys_extrasleep.value);
 	}
 #endif
+	return (1);	/* should never reach here */
 }
 
