--- src/ccutil/ocrclass.h.orig	2019-07-08 13:00:14 UTC
+++ src/ccutil/ocrclass.h
@@ -31,6 +31,7 @@
 #ifdef _WIN32
 #include <winsock2.h> // for timeval
 #endif
+#include <sys/time.h>
 
 /**********************************************************************
  * EANYCODE_CHAR
