--- sources/main.cpp.orig	2006-02-18 00:31:24.000000000 +0300
+++ sources/main.cpp	2008-05-15 00:44:41.000000000 +0400
@@ -2,6 +2,10 @@
 #include <windows.h>
 #endif
 
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <unistd.h>
+#include <err.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include "math.h"
@@ -235,6 +239,19 @@
 int main(int argc, char** argv)
 {
 #endif
+	if (chdir(getenv("HOME")) != 0)
+		err(1, "Cannot chdir to $HOME");
+
+	struct stat sb;
+	if (stat(".f1spirit-remake", &sb) != 0 &&
+			(mkdir(".f1spirit-remake", 0755) != 0 ||
+			mkdir(".f1spirit-remake/highscores", 0755) != 0 ||
+			mkdir(".f1spirit-remake/players", 0755) != 0 ||
+			mkdir(".f1spirit-remake/replays", 0755) != 0))
+		err(1, "Cannot make directory");
+
+	if (chdir(".f1spirit-remake") != 0)
+		err(1, "Cannot chdir to $HOME/.f1spirit-remake");
 
 	SDL_Surface *screen_sfc;
 	F1SpiritApp *game;
