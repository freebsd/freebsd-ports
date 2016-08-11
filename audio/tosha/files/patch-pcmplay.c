--- pcmplay.c.orig	1999-01-01 23:57:41 UTC
+++ pcmplay.c
@@ -44,7 +44,7 @@ static const char cvsid[]
 #include <sys/types.h>
 #include <sys/uio.h>
 #include <unistd.h>
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 
 #include "utils.h"
 #include "getlopt.h"
