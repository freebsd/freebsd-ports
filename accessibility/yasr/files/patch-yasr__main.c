--- yasr/main.c.orig	2007-09-23 00:46:58 UTC
+++ yasr/main.c
@@ -24,11 +24,7 @@
 
 #include "yasr.h"
 #include "term.h"
-#include <utmp.h>
-#ifdef HAVE_UTMPX_H
 #include <utmpx.h>
-#endif
-#define UTMP_HACK
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/wait.h>
