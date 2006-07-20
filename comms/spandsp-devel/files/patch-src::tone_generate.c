
$FreeBSD$

--- src/tone_generate.c
+++ src/tone_generate.c
@@ -39,6 +39,7 @@
 #include <stdio.h>
 #include <time.h>
 #include <fcntl.h>
+#include <tgmath.h>
 
 #include "spandsp/telephony.h"
 #include "spandsp/dc_restore.h"
