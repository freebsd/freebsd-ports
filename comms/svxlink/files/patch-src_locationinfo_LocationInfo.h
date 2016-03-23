--- src/locationinfo/LocationInfo.h.orig	2016-02-23 13:03:56.000000000 +0100
+++ src/locationinfo/LocationInfo.h	2016-02-23 13:07:13.000000000 +0100
@@ -38,7 +38,7 @@
 #include <string>
 #include <vector>
 #include <list>
-
+#include <sys/time.h> // for struct timeval
 
 /****************************************************************************
  *
