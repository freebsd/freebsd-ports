--- libhsclient/fatal.cpp.orig	2011-06-14 03:03:49.000000000 +0000
+++ libhsclient/fatal.cpp
@@ -7,6 +7,7 @@
  */
 
 #include <stdlib.h>
+#include <unistd.h>
 #include <stdio.h>
 #include <syslog.h>
 
