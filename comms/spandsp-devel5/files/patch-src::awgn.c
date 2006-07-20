
$FreeBSD$

--- src/awgn.c
+++ src/awgn.c
@@ -51,6 +51,7 @@
 #include <stdio.h>
 #include <inttypes.h>
 #include <math.h>
+#include <tgmath.h>
 
 #include "spandsp/dc_restore.h"
 #include "spandsp/awgn.h"
