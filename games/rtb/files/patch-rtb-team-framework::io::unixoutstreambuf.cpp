--- rtb-team-framework/io/unixoutstreambuf.cpp.orig	Wed Nov  3 05:09:04 2004
+++ rtb-team-framework/io/unixoutstreambuf.cpp	Fri Dec 17 01:34:44 2004
@@ -26,6 +26,7 @@
 
 #include "unixoutstreambuf.h"
 #include <sstream>
+#include <cerrno>
 
 /**
  * Namespace
