--- _pycapsicum.c.orig	2019-09-01 13:05:23 UTC
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
 
