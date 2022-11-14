--- libcyberjack/checksuite/cm_distri.cpp.orig	2021-11-03 13:00:16 UTC
+++ libcyberjack/checksuite/cm_distri.cpp
@@ -10,8 +10,9 @@
  ***************************************************************************/
 
 
+#include "config.h"
+#include "Platform.h"
 
-
 #include "cm_distri.h"
 #include "checksuite.h"
 
@@ -21,6 +22,10 @@
 #include <string.h>
 #include <unistd.h>
 
+#ifdef OS_FREEBSD
+#include <sys/types.h>
+#include <sys/wait.h>
+#endif
 
 
 bool CM_Distri::check(std::string &xmlString,
