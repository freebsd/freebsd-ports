--- src/liba52/xine_decoder.c.orig	Fri Oct 19 17:55:03 2001
+++ src/liba52/xine_decoder.c	Fri Oct 19 17:55:31 2001
@@ -31,8 +31,8 @@
 #include <fcntl.h>
 
 #include "audio_out.h"
-#include "a52.h"
-#include "a52_internal.h"
+#include <a52dec/a52.h>
+#include <a52dec/a52_internal.h>
 #include "buffer.h"
 #include "xine_internal.h"
 #include "cpu_accel.h"
