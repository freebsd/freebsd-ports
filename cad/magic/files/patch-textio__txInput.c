--- textio/txInput.c.orig	2026-03-27 06:00:02 UTC
+++ textio/txInput.c
@@ -30,6 +30,7 @@ static char rcsid[] __attribute__ ((unused)) = "$Heade
 #include <unistd.h>
 #include <ctype.h>
 #include <dirent.h>
+#include <termios.h>
 
 
 #include "utils/magic.h"
