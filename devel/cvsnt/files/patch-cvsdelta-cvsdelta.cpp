--- cvsdelta/cvsdelta.cpp.orig	Sun Feb 22 03:05:15 2004
+++ cvsdelta/cvsdelta.cpp	Sun Feb 22 03:04:56 2004
@@ -10,7 +10,6 @@
  * the rest thrown together from a mixture of inspiration and google.
  */
 
-#include <malloc.h>
 #include <stdio.h>
 #include <assert.h>
 #include <string.h>
@@ -20,6 +19,7 @@
 #if defined(_WIN32)
   #include <winsock2.h>
 #else
+  #include <sys/types.h>
   #include <netinet/in.h>
 #endif
 
