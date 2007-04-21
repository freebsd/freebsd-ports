--- engine/qcommon/common.c.orig	Thu Apr 19 21:42:48 2007
+++ engine/qcommon/common.c	Thu Apr 19 21:49:46 2007
@@ -23,6 +23,7 @@
 
 #include "q_shared.h"
 #include "qcommon.h"
+#include <sys/types.h>
 #include <setjmp.h>
 
 int demo_protocols[] =
