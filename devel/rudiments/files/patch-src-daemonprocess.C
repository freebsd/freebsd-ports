--- src/daemonprocess.C.orig	Mon Apr 15 06:21:24 2002
+++ src/daemonprocess.C	Sun Feb 29 01:53:19 2004
@@ -5,7 +5,7 @@
 
 #include <iostream.h>
 #include <fstream.h>
-#include <strstream.h>
+#include <strstream>
 
 #include <sys/types.h>
 #ifdef HAVE_UNISTD_H
@@ -22,11 +22,13 @@
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
+
+using namespace std;
 
 daemonprocess::daemonprocess() {
 
