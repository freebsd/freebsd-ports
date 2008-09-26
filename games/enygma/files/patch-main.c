--- main.c.orig	Sun Sep 14 23:23:51 2008
+++ main.c	Sun Sep 14 22:13:48 2008
@@ -11,6 +11,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include "enigma.h"
 
@@ -131,7 +132,7 @@
 			char *fname;
 			char *sequence;
 			gamestate **movie;
-			int nframes;
+			int nframes = 0;
 			int frame;
 			char msg[80];
 			int km;
