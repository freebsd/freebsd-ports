--- plugins/r/src/tm_r.c.orig	2010-01-05 12:02:13.000000000 -0800
+++ plugins/r/src/tm_r.c	2010-01-05 12:06:43.000000000 -0800
@@ -11,10 +11,15 @@
 
 #include "config.h"
 #include <stdio.h>
+#include <sys/types.h>
 #include <sys/select.h>
+#ifdef __FreeBSD__
+#include <libutil.h>
+#else
 #if HAVE_PTY_H
 #include <pty.h>
 #endif
+#endif
 #include <utmp.h>
 #include <unistd.h>
 #include <termios.h>
@@ -23,7 +28,6 @@
 #include <string.h>
 
 
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <sys/time.h>
@@ -469,7 +473,11 @@
 #endif
 
       /* Main pselect switch --------------- */
+#if defined(__FreeBSD__) && __FreeBSD__ < 5
+      if( select( master+1, &rd, &wr, &er, NULL ) > 0 ) {
+#else
       if( pselect( master+1, &rd, &wr, &er, NULL, &orig_sigmask ) > 0 ) {
+#endif
 	if( FD_ISSET( STDIN_FILENO, &rd ) ) {
 	  /* =============== read input from TeXmacs */
 	  nread = read_B( STDIN_FILENO, RB, 1000 ) ;
