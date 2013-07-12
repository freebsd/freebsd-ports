--- sources/main.cpp.orig	2005-04-16 21:16:54.000000000 +0400
+++ sources/main.cpp	2008-04-07 01:37:52.000000000 +0400
@@ -6,6 +6,9 @@
 #include <time.h>
 #endif
 
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include "SDL/SDL.h"
@@ -126,6 +128,19 @@
 	setupTickCount();
 #endif
 
+	if (chdir(getenv("HOME")) != 0)
+		return 0;
+
+	struct stat sb;
+	if (stat(".stransball2", &sb) != 0 &&
+			(mkdir(".stransball2", 0755) != 0 ||
+			 mkdir(".stransball2/high", 0755) != 0 ||
+			 mkdir(".stransball2/replays", 0755) != 0))
+		return 0;
+
+	if (chdir(".stransball2") != 0)
+		return 0;
+
 	int time,act_time;
 	SDL_Event event;
     bool quit = false;
