--- src/Task.h.orig	2013-09-17 10:56:44.000000000 +0200
+++ src/Task.h	2013-09-17 10:56:57.000000000 +0200
@@ -33,6 +33,7 @@
 #include <map>
 #include <string>
 #include <stdio.h>
+#include <sys/time.h>
 
 
 void initializeUrgencyCoefficients ();
