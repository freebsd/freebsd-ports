--- ./engine/unix/unix_shared.c.orig	Wed Dec 20 20:28:48 2006
+++ ./engine/unix/unix_shared.c	Sat Dec 23 11:21:39 2006
@@ -78,7 +78,7 @@
 	return curtime;
 }
 
-#if defined(__linux__) && !defined(DEDICATED)
+#if defined(__unix__) && !defined(DEDICATED)
 /*
 ================
 Sys_XTimeToSysTime
@@ -143,7 +143,7 @@
 
 //#if 0 // bk001215 - see snapvector.nasm for replacement
 // rcg010206 - using this for PPC builds...
-#if defined(__APPLE__) || (defined(__linux__) && defined(C_ONLY)) || defined(__x86_64__)
+#if defined(__APPLE__) || (defined(__unix__) && defined(C_ONLY)) || defined(__x86_64__)
 //#if !(defined __i386__)
 long fastftol(float f)
 {								// bk001213 - from win32/win_shared.c
@@ -459,7 +459,7 @@
 	return p->pw_name;
 }
 
-#if defined(__linux__)
+#if defined(__unix__)
 // TTimo 
 // sysconf() in libc, POSIX.1 compliant
 unsigned int Sys_ProcessorCount()
