--- src/script.c.orig	2011-07-23 19:58:32.000000000 +0200
+++ src/script.c	2011-12-28 16:07:59.000000000 +0100
@@ -69,7 +69,7 @@ struct env {
 struct env *curenv;		/* Execution environment */
 int gtimeout = 120;		/* Global Timeout */
 int etimeout = 0;		/* Timeout in expect routine */
-jmp_buf ejmp;			/* To jump to if expect times out */
+sigjmp_buf ejmp;		/* To jump to if expect times out */
 int inexpect = 0;		/* Are we in the expect routine */
 const char *newline;		/* What to print for '\n'. */
 const char *s_login = "name";	/* User's login name */
