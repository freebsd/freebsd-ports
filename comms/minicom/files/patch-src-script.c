--- src/script.c.orig	2013-10-29 12:07:42.000000000 +0100
+++ src/script.c	2014-01-02 20:30:55.000000000 +0100
@@ -32,6 +32,7 @@
 #include <config.h>
 #endif
 
+#include <sys/wait.h>
 #include <stdarg.h>
 
 #include "port.h"
@@ -76,7 +77,7 @@ struct env {
 struct env *curenv;		/* Execution environment */
 int gtimeout = 120;		/* Global Timeout */
 int etimeout = 0;		/* Timeout in expect routine */
-jmp_buf ejmp;			/* To jump to if expect times out */
+sigjmp_buf ejmp;		/* To jump to if expect times out */
 int inexpect = 0;		/* Are we in the expect routine */
 const char *newline;		/* What to print for '\n'. */
 const char *s_login = "name";	/* User's login name */
