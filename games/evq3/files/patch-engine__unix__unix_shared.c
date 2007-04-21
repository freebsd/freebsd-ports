--- ./engine/unix/unix_shared.c.orig	Sat Mar 31 20:25:26 2007
+++ ./engine/unix/unix_shared.c	Tue Apr 17 00:00:39 2007
@@ -76,7 +76,7 @@
 	return curtime;
 }
 
-#if (defined(__linux__) || defined(__FreeBSD__) || defined(__sun)) && !defined(DEDICATED)
+#if (defined(__unix__) || defined(__sun)) && !defined(DEDICATED)
 /*
 ================
 Sys_XTimeToSysTime
@@ -441,7 +441,7 @@
 	return p->pw_name;
 }
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#ifdef __unix__
 // TTimo 
 // sysconf() in libc, POSIX.1 compliant
 unsigned int Sys_ProcessorCount(void)
