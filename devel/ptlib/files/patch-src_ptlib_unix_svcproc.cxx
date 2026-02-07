--- src/ptlib/unix/svcproc.cxx.orig	2013-09-20 14:46:03.000000000 +0200
+++ src/ptlib/unix/svcproc.cxx	2013-09-20 14:46:46.000000000 +0200
@@ -217,7 +217,7 @@
     pid_t pid;
 
     {
-      ifstream pidfile(pidfilename);
+      ifstream pidfile((const char*)pidfilename);
       if (!pidfile.is_open()) {
         cout << "Could not open pid file: \"" << pidfilename << "\""
                 " - " << strerror(errno) << endl;
@@ -384,7 +384,7 @@
   // Run as a daemon, ie fork
 
   if (!pidfilename) {
-    ifstream pidfile(pidfilename);
+    ifstream pidfile((const char*)pidfilename);
     if (pidfile.is_open()) {
       pid_t pid;
       pidfile >> pid;
@@ -412,7 +412,7 @@
       cout << "Daemon started with pid " << pid << endl;
       if (!pidfilename) {
         // Write out the child pid to magic file in /var/run (at least for linux)
-        ofstream pidfile(pidfilename);
+        ofstream pidfile((const char*)pidfilename);
         if (pidfile.is_open())
           pidfile << pid;
         else
