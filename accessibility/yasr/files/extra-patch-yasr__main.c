--- ./yasr/main.c.orig	2013-11-11 18:44:59.238198747 -0500
+++ ./yasr/main.c	2013-11-11 18:45:09.927197900 -0500
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
