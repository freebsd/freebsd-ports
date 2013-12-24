--- psconv.c.orig
+++ psconv.c
@@ -64,9 +64,11 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #include <signal.h>
+#include <unistd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 
