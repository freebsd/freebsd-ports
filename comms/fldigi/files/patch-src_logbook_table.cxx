--- src/logbook/table.cxx.orig	2020-10-17 12:50:46 UTC
+++ src/logbook/table.cxx
@@ -46,10 +46,11 @@ using namespace std;
  * nullptr is not available in gcc < 4.6
  * Redefine to NULL for CentOS 6 and OSX Darwin
  */
+#ifndef __FreeBSD__
 #ifndef nullptr
 #define nullptr NULL
 #endif
-
+#endif
 
 /*
  * ======================================
