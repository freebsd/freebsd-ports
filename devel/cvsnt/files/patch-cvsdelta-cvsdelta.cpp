--- cvsdelta/cvsdelta.cpp.orig	Thu Mar  4 01:17:46 2004
+++ cvsdelta/cvsdelta.cpp	Thu Mar  4 01:18:01 2004
@@ -23,6 +23,7 @@
 #if defined(_WIN32)
   #include <winsock2.h>
 #else
+  #include <sys/types.h>
   #include <netinet/in.h>
 #endif
 
