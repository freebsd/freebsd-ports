--- textio/txInput.c.orig	2023-07-12 06:00:01 UTC
+++ textio/txInput.c
@@ -28,6 +28,7 @@ static char rcsid[] __attribute__ ((unused)) = "$Heade
 #include <unistd.h>
 #include <ctype.h>
 #include <dirent.h>
+#include <termios.h>
 
 
 #include "utils/magsgtty.h"
@@ -1208,14 +1209,14 @@ TxGetLine(dest, maxChars)
  * ----------------------------------------------------------------------------
  */
 
-#if defined(SYSV) || defined(CYGWIN)
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
 
 void
 txGetTermState(buf)
-    struct termio *buf;
+    struct termios *buf;
 
 {
-    ioctl( fileno( stdin ), TCGETA, buf);
+    ioctl( fileno( stdin ), TIOCGETA, buf);
 }
 
 #elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
@@ -1257,7 +1258,7 @@ txSetTermState(buf)
 
 void
 txSetTermState(buf)
-#if defined(SYSV) || defined(CYGWIN)
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__)
     struct termio *buf;
 #elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
     struct termios *buf;
@@ -1267,7 +1268,7 @@ txSetTermState(buf)
 {
 #if defined(SYSV) || defined(CYGWIN)
     ioctl( fileno(stdin), TCSETAF, buf );
-#elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
+#elif defined(__FreeBSD__) || defined (__OpenBSD__) || defined(EMSCRIPTEN)
     (void) tcsetattr( fileno(stdin), TCSANOW, buf );
 #else
     /* set the current terminal characteristics */
@@ -1298,13 +1299,13 @@ txInitTermRec(buf)
 txInitTermRec(buf)
 #if defined(SYSV) || defined(CYGWIN)
     struct termio *buf;
-#elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
+#elif defined(__FreeBSD__) || defined (__OpenBSD__) || defined(EMSCRIPTEN)
     struct termios *buf;
 #else
     txTermState *buf;
 #endif /* SYSV */
 {
-#if defined(SYSV) || defined(CYGWIN) || defined(__OpenBSD__) || defined(EMSCRIPTEN)
+#if defined(SYSV) || defined(CYGWIN) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(EMSCRIPTEN)
     buf->c_lflag = ISIG;    /* raw: no echo and no processing, allow signals */
     buf->c_cc[ VMIN ] = 1;
     buf->c_cc[ VTIME ] = 0;
@@ -1321,7 +1322,7 @@ struct termio closeTermState;
 
 #if defined(SYSV) || defined(CYGWIN)
 struct termio closeTermState;
-#elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
+#elif defined(__FreeBSD__) || defined (__OpenBSD__) || defined(EMSCRIPTEN)
 struct termios closeTermState;
 #else
 static txTermState closeTermState;
@@ -1349,13 +1350,13 @@ txSaveTerm()
 txSaveTerm()
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
@@ -1398,7 +1399,7 @@ TxSetTerminal()
 {
 #if defined(SYSV) || defined(CYGWIN)
     struct termio buf;
-#elif defined (__OpenBSD__) || defined(EMSCRIPTEN)
+#elif defined(__FreeBSD__) || defined (__OpenBSD__) || defined(EMSCRIPTEN)
     struct termios buf;
 #else
     txTermState buf;
