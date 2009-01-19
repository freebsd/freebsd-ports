--- play.cc.orig	2009-01-18 01:21:03.000000000 +0300
+++ play.cc	2009-01-19 08:14:26.000000000 +0300
@@ -30,6 +30,9 @@
 #include "SDL_mixer.h"
 #include "SDL_thread.h"
 #include "SDL_ttf.h"
+#include <unistd.h>
+#include <err.h>
+#include <sys/stat.h>
 
 #include "config.h"
 #include "game.h"
@@ -2028,6 +2031,15 @@
 
 int main(int argc, char** argv)
 {
+  {
+    if (chdir(getenv("HOME")) != 0)
+      err(1, "cannot cd to $HOME");
+    if (mkdir(".kartofel", 0755) != 0 && errno != EEXIST)
+      err(1, "cannot mkdir $HOME/.kartofel");
+    if (chdir(".kartofel") != 0)
+      err(1, "cannot cd to $HOME/.kartofel");
+  }
+
   kartofel::Run();
   return 0;
 }
