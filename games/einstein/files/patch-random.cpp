--- /dev/null	1 Jan 1970 00:00:00 -0000
+++ files/patch-random.cpp	7 Mar 2005 16:00:23 -0000
@@ -0,0 +1,11 @@
+
+$FreeBSD$
+
+--- random.cpp.orig
++++ random.cpp
+@@ -1,3 +1,5 @@
++#include "sys/time.h"
++
+ #include "random.h"
+ #include "utils.h"
+
