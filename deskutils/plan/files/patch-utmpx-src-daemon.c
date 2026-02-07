--- daemon.c.orig	2010-01-25 17:34:06.000000000 -0800
+++ daemon.c	2010-01-25 17:38:29.000000000 -0800
@@ -42,7 +42,7 @@
 #ifdef __EMX__
 #include <io.h>
 #else
-#include <utmp.h>
+#include <utmpx.h>
 #endif
 #ifdef AIXV3
 struct utmp *getutent();
@@ -266,7 +266,7 @@
 		refresh_lock(resolve_tilde(PLANDLOCK));
 		logged_in = FALSE;
 		if (pw) {
-#if defined(SUN) || defined(BSD) || defined(__FreeBSD__)
+#if defined(SUN)
 		    struct utmp	ut;
 		    int		fd;
 		    int		l;
@@ -289,9 +289,9 @@
 		    logged_in = TRUE;
 #else
 		    short pid = getpid();
-		    struct utmp *u;
-		    setutent();
-		    while ((u = getutent()))
+		    struct utmpx *u;
+		    setutxent();
+		    while ((u = getutxent()))
 			if (u->ut_type == USER_PROCESS &&
 			    u->ut_pid != pid &&
 			    !strncmp(pw->pw_name, u->ut_user, 8)) {
