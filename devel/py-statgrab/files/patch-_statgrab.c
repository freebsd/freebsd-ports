--- _statgrab.c.bak	Wed May 19 23:11:40 2004
+++ _statgrab.c	Wed May 19 23:11:49 2004
@@ -2,6 +2,7 @@
 
 #include "Python.h"
 #include "structmember.h"
+#define SG_ENABLE_DEPRECATED
 #include "statgrab.h"
 
 
