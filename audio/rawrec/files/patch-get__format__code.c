--- get_format_code.c.orig	2006-01-05 17:36:27 UTC
+++ get_format_code.c
@@ -7,7 +7,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 #include "rawrec.h"
 
