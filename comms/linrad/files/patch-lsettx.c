--- lsettx.c.orig	Thu Sep 27 21:53:04 2007
+++ lsettx.c	Thu Sep 27 21:53:16 2007
@@ -5,6 +5,7 @@
 #include <ctype.h>
 #include <math.h>
 #include <semaphore.h>
+#include <pthread.h>
 
 #include "globdef.h"
 #include "uidef.h"
