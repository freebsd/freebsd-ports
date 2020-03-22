https://github.com/stillson/pycapsicum2/pull/3

--- _pycapsicum.c.orig	2020-03-22 05:41:16 UTC
+++ _pycapsicum.c
@@ -32,11 +32,7 @@
 #include <fcntl.h>
 
 #include "Python.h"
-#if OSVERSION < 1020000
-#include "sys/capability.h"
-#else
 #include "sys/capsicum.h"
-#endif
 #include "sys/caprights.h"
 #include "structmember.h"
 
