--- classes/unix/unixkey.cc.orig	2026-06-21 19:50:02 UTC
+++ classes/unix/unixkey.cc
@@ -22,6 +22,7 @@ key, Shift+(Inset,End,Home,PgUp,PgDn,Delete,Arrows,etc
 key, Shift+(Inset,End,Home,PgUp,PgDn,Delete,Arrows,etc.) and more.
 
 *****************************************************************************/
+#include <termios.h>
 #include <tv/configtv.h>
 
 #define Uses_stdio
