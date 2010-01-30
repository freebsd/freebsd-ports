--- src/levelblit.c.orig	2008-01-15 03:54:41.000000000 +0100
+++ src/levelblit.c	2010-01-30 10:07:22.000000000 +0100
@@ -27,7 +27,12 @@
 #include <SDL.h>
 #include <SDL_image.h>
 #include <assert.h>
-
+
+#include <errno.h>
+#include <unistd.h>
+#include <err.h>
+#include <sys/stat.h>
+
 #include "mapgen.h"
 #include "demon.h"
 #include "gamemap.h"
@@ -378,6 +383,14 @@
 
 int main(int argc, char **argv)
 {
+	{
+		if (chdir(getenv("HOME")) != 0)
+			err(1, "cannot cd to $HOME");
+		if (mkdir(".meritous", 0755) != 0 && errno != EEXIST)
+			err(1, "cannot mkdir $HOME/.meritous");
+		if (chdir(".meritous") != 0)
+			err(1, "cannot cd to $HOME/.meritous");
+	}
 	int on_title = 1;
 	int executable_running = 1;
 	SDL_Surface *title, *title_pr, *asceai;
