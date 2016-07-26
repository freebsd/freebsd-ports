--- raw_a.c.orig	1996-05-20 13:09:47 UTC
+++ raw_a.c
@@ -35,6 +35,7 @@
 
 #ifdef __FreeBSD__
 #include <stdio.h>
+#include <string.h>
 #endif
 
 #include "config.h"
