--- src/daemonprocess.C.orig	Tue Oct 28 07:43:40 2003
+++ src/daemonprocess.C	Tue Oct 28 07:43:46 2003
@@ -22,10 +22,10 @@
 #include <rudiments/daemonprocess.h>
 
 #ifdef __GNUC__
-static	signalhandler	*daemonprocess::termhandler;
-static	signalhandler	*daemonprocess::inthandler;
-static	void		(*daemonprocess::shutdownfunc)(int);
-static	signalhandler	*daemonprocess::deadchildhandler;
+signalhandler	*daemonprocess::termhandler;
+signalhandler	*daemonprocess::inthandler;
+void		(*daemonprocess::shutdownfunc)(int);
+signalhandler	*daemonprocess::deadchildhandler;
 #endif
 
 daemonprocess::daemonprocess() {
