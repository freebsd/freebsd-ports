--- src/script.c.orig	2022-01-06 04:57:01 UTC
+++ src/script.c
@@ -77,7 +77,7 @@ struct env {
 struct env *curenv;		/* Execution environment */
 int gtimeout = 120;		/* Global Timeout */
 int etimeout = 0;		/* Timeout in expect routine */
-jmp_buf ejmp;			/* To jump to if expect times out */
+sigjmp_buf ejmp;		/* To jump to if expect times out */
 int inexpect = 0;		/* Are we in the expect routine */
 const char *newline;		/* What to print for '\n'. */
 const char *s_login = "name";	/* User's login name */
