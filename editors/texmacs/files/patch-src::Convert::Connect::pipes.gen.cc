--- src/Convert/Connect/pipes.gen.cc.orig	Sat Dec 15 23:51:53 2001
+++ src/Convert/Connect/pipes.gen.cc	Sun Nov 24 21:16:13 2002
@@ -24,7 +24,6 @@
 #include <string.h>
 #include <unistd.h>
 #include <signal.h>
-#include <malloc.h>
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/wait.h>
@@ -340,7 +339,7 @@
 ******************************************************************************/
 
 string
-connection_start (string name, string session, bool again=FALSE) {
+connection_start (string name, string session, bool again) {
   // cout << "Start " << name << ", " << session << "\n";
   if (!connection_declared (name))
     return "Error: connection " * name * " has not been declared";
