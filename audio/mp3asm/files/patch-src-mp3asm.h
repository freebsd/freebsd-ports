--- src/mp3asm.h.orig	2001-03-20 01:45:48 UTC
+++ src/mp3asm.h
@@ -30,7 +30,6 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sysexits.h>
-#include <argz.h>
 #include <ctype.h>
 
 #define LOGBUFSIZE 4096
@@ -46,7 +45,7 @@ extern int verbosity;
 extern int quiet;
 extern int info; /* if set to 1 -> print header info on all files and exit */
 extern char *me; /* name of the executable */
-extern logfile_t log; /* file to log to */
+extern logfile_t mp3asm_log; /* file to log to */
 extern int inputs;
 
 #endif /* HAVE_MP3ASM_H */
