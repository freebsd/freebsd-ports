--- ./src/frontend/aspice.c.orig	Sat Jun 24 01:39:15 2006
+++ ./src/frontend/aspice.c	Sat Jun 24 01:39:39 2006
@@ -176,7 +176,7 @@
  * whether the exit was normal or not.
  */
 
-#if defined(__NetBSD__) || defined(SOLARIS)
+#if defined(__NetBSD__) || defined(SOLARIS) || defined(__FreeBSD__)
     pid_t status;
 #else
     union wait status;
