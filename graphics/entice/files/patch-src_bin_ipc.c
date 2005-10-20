--- src/bin/ipc.c.orig	Thu Oct 20 13:54:46 2005
+++ src/bin/ipc.c	Thu Oct 20 13:54:54 2005
@@ -2,6 +2,7 @@
 #include "ipc.h"
 #include <Ecore_Ipc.h>
 #include <limits.h>
+#include <stdio.h>
 #include <stdlib.h>
 
 #define IPC_TITLE "entice"
