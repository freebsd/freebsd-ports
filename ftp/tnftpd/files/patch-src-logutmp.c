--- src/logutmp.c-orig	Mon Feb 24 07:38:44 2003
+++ src/logutmp.c	Thu Jan 22 11:59:38 2004
@@ -40,10 +40,10 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <time.h>
 #include <ttyent.h>
 #include <unistd.h>
 #include <utmp.h>
-#include <util.h>
 
 #include "extern.h"
 
