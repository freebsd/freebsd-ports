--- klos.c.orig	2012-12-03 13:51:56.000000000 +0100
+++ klos.c	2012-12-03 13:53:25.000000000 +0100
@@ -83,9 +83,12 @@
 #define KlWaitPid(statusp) wait3(statusp, WNOHANG, 0)
 #endif
 
+
 DECLARE_strchr;
 
 KlRSignal KlChildDeathHandler();
+void KlSignalHandlerExecuteAux(int, KlO);
+void KlProcessIdDies(int, int);
 
 /* On SYSV signals where it is possible (AIX), use an emulation of the BSD 
  * signal call via sigaction. 
@@ -777,6 +780,7 @@
 
 /* a process is signalled to be dead */
 
+void
 KlProcessIdDies(pid, status)
     int pid;
     int status;
@@ -1591,6 +1595,7 @@
 #endif
 }
 
+void
 KlSignalHandlerExecuteAux(sig, handler)
     int sig;
     KlO handler;
