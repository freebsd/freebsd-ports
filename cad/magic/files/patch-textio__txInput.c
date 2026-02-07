--- textio/txInput.c.orig	2025-02-24 07:00:02 UTC
+++ textio/txInput.c
@@ -28,6 +28,7 @@ static char rcsid[] __attribute__ ((unused)) = "$Heade
 #include <unistd.h>
 #include <ctype.h>
 #include <dirent.h>
+#include <termios.h>
 
 
 #include "utils/magsgtty.h"
@@ -1221,13 +1222,13 @@ TxGetLine(
  * ----------------------------------------------------------------------------
  */
 
-#if defined(SYSV) || defined(CYGWIN)
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
 
 void
 txGetTermState(
-    struct termio *buf)
+    struct termios *buf)
 {
-    ioctl( fileno( stdin ), TCGETA, buf);
+    ioctl( fileno( stdin ), TIOCGETA, buf);
 }
 
 #elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
@@ -1269,7 +1270,7 @@ txSetTermState(
 
 void
 txSetTermState(
-#if defined(SYSV) || defined(CYGWIN)
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
     struct termio *buf
 #elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
     struct termios *buf
@@ -1280,7 +1281,7 @@ txSetTermState(
 {
 #if defined(SYSV) || defined(CYGWIN)
     ioctl( fileno(stdin), TCSETAF, buf );
-#elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
+#elif defined(__FreeBSD__) || defined (__OpenBSD__) || defined(EMSCRIPTEN)
     (void) tcsetattr( fileno(stdin), TCSANOW, buf );
 #else
     /* set the current terminal characteristics */
@@ -1311,14 +1312,14 @@ txInitTermRec(
 txInitTermRec(
 #if defined(SYSV) || defined(CYGWIN)
     struct termio *buf
-#elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
+#elif defined(__FreeBSD__) || defined (__OpenBSD__) || defined(EMSCRIPTEN)
     struct termios *buf
 #else
     txTermState *buf
 #endif /* SYSV */
     )
 {
-#if defined(SYSV) || defined(CYGWIN) || defined(__OpenBSD__) || defined(EMSCRIPTEN)
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(EMSCRIPTEN)
     buf->c_lflag = ISIG;    /* raw: no echo and no processing, allow signals */
     buf->c_cc[ VMIN ] = 1;
     buf->c_cc[ VTIME ] = 0;
@@ -1335,7 +1336,7 @@ struct termio closeTermState;
 
 #if defined(SYSV) || defined(CYGWIN)
 struct termio closeTermState;
-#elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
+#elif defined(__FreeBSD__) || defined (__OpenBSD__) || defined(EMSCRIPTEN)
 struct termios closeTermState;
 #else
 static txTermState closeTermState;
@@ -1363,13 +1364,13 @@ txSaveTerm(void)
 txSaveTerm(void)
 {
 #if defined(SYSV) || defined(CYGWIN)
-    ioctl( fileno( stdin ), TCGETA, &closeTermState);
+    ioctl( fileno( stdin ), TIOCGETA, &closeTermState);
     txEraseChar = closeTermState.c_cc[VERASE];
     txKillChar =  closeTermState.c_cc[VKILL];
     TxEOFChar = closeTermState.c_cc[VEOF];
     TxInterruptChar = closeTermState.c_cc[VINTR];
     haveCloseState = TRUE;
-#elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
+#elif defined(__FreeBSD__) || defined (__OpenBSD__) || defined(EMSCRIPTEN)
     (void) tcgetattr( fileno( stdin ), &closeTermState);
     txEraseChar = closeTermState.c_cc[VERASE];
     txKillChar =  closeTermState.c_cc[VKILL];
@@ -1412,7 +1413,7 @@ TxSetTerminal(void)
 {
 #if defined(SYSV) || defined(CYGWIN)
     struct termio buf;
-#elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
+#elif defined(__FreeBSD__) || defined (__OpenBSD__) || defined(EMSCRIPTEN)
     struct termios buf;
 #else
     txTermState buf;
