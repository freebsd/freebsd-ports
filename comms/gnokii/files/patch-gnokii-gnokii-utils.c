--- gnokii/gnokii-utils.c.orig	2007-12-06 14:24:37.000000000 +0100
+++ gnokii/gnokii-utils.c	2007-12-06 14:25:25.000000000 +0100
@@ -43,6 +43,8 @@
 
 #include <stdio.h>
 #include <signal.h>
+#include <sys/types.h>
+#include <sys/stat.h>
 
 #include "gnokii-app.h"
 #include "gnokii.h"
