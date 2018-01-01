--- bwb_cmd.c.orig	2018-01-01 11:17:18 UTC
+++ bwb_cmd.c
@@ -40,6 +40,7 @@
 
 
 
+#include <string.h>
 #include "bwbasic.h"
 
 static void bwb_copy_file (char *Source, char *Target);
