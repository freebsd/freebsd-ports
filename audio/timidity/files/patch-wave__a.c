--- wave_a.c.orig	1996-05-20 13:10:15 UTC
+++ wave_a.c
@@ -35,6 +35,7 @@
 
 #ifdef __FreeBSD__
 #include <stdio.h>
+#include <string.h>
 #endif
 
 #include "config.h"
