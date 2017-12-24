--- main.c.orig	2004-02-28 10:01:16 UTC
+++ main.c
@@ -11,6 +11,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include "enigma.h"
 
@@ -131,7 +132,7 @@ int main(int argc, char **argv) {
 			char *fname;
 			char *sequence;
 			gamestate **movie;
-			int nframes;
+			int nframes = 0;
 			int frame;
 			char msg[80];
 			int km;
