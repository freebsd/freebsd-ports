--- pcmplay.c.old	Sat Jan  2 08:57:41 1999
+++ pcmplay.c	Thu Apr 11 08:00:07 2002
@@ -44,7 +44,7 @@
 #include <sys/types.h>
 #include <sys/uio.h>
 #include <unistd.h>
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 
 #include "utils.h"
 #include "getlopt.h"
