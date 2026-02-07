--- src/games.c.orig	2003-09-25 15:54:27 UTC
+++ src/games.c
@@ -25,14 +25,13 @@
 #ifdef	HAVE_UNISTD_H
 #include	<unistd.h>
 #endif				/* HAVE_UNISTD_H */
+#include	<errno.h>
 
 #include	"cntl.h"
 #include	"data.h"
 #include	"games.h"
 #include	"print.h"
 
-extern int	errno;
-
 #define MAX_GAMES 50
 
 typedef struct {
