--- src/util.c.orig	Fri Oct 25 11:42:37 2002
+++ src/util.c	Fri Oct 25 11:43:05 2002
@@ -138,7 +138,7 @@
 ReapChild()
 {
 /* QNX support added by D J Hawkey Jr <hawkeyd@visi.com> 1997May16 */
-#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4) && !defined(__QNX__)
+#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4) && !defined(__QNX__) && !defined(__FreeBSD__)
   int pid;
 #endif
   extern int errno;
@@ -149,7 +149,7 @@
   * checked into it.  This gets us off the ground with SYSV.  RSE@GMI
   * QNX support added by Frank G Liu <liug@cs.rose-hulman.edu> 1997May09
   */
-#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4) && !defined(__QNX__)
+#if defined(WNOHANG) && !defined(SYSV) && !defined(SVR4) && !defined(__QNX__) && !defined(__FreeBSD__)
   union wait st;
 
   do 
