--- demo/demo.cpp.orig	Sun Sep  9 21:09:08 2001
+++ demo/demo.cpp	Sun Sep  9 21:09:16 2001
@@ -33,7 +33,6 @@
 #include <xmem.h>
 
 #ifdef USE_NCURSES /* alias we're not under Windoze */
-#include <unistd.h>
 #endif
 
 const char rcsid[] = "$Id: demo.cpp,v 1.17 2001/09/05 09:31:04 darkmoon Exp $";
