--- src/membergroup.cpp.orig	2022-09-18 12:47:12 UTC
+++ src/membergroup.cpp
@@ -15,6 +15,8 @@
  *
  */
 
+#include <sys/types.h>
+
 #include "membergroup.h"
 #include "memberlist.h"
 #include "outputlist.h"
