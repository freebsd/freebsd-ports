--- src/callinput.c.orig	Sat Jul 10 21:33:41 2004
+++ src/callinput.c	Sat Jul 10 21:34:33 2004
@@ -26,6 +26,7 @@
 #include "addspot.h"
 #include "changefreq.h"

+void send_bandswitch(int freq);


 int callinput(void)
@@ -105,7 +106,6 @@

 instring[1] = '\0';

-void send_bandswitch(int freq);

 if (use_rxvt == 0) attron(COLOR_PAIR(NORMCOLOR) | A_BOLD );
 else     attron(COLOR_PAIR(NORMCOLOR) );
