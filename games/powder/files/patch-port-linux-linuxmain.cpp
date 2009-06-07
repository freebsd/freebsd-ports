--- port/linux/linuxmain.cpp.orig	2008-01-10 06:26:42.000000000 +0300
+++ port/linux/linuxmain.cpp	2009-06-08 00:37:41.000000000 +0400
@@ -1,4 +1,8 @@
 #include <SDL.h>
+#include <err.h>
+#include <stdlib.h>
+#include <sys/stat.h>
+#include <unistd.h>
 
 #ifdef main
 #undef main
@@ -11,6 +15,15 @@
 
 int main(int argc, char **argv)
 {
+	{
+		if (chdir(getenv("HOME")) != 0)
+			err(1, "cannot cd to $HOME");
+		if (mkdir(".powder", 0755) != 0 && errno != EEXIST)
+			err(1, "cannot mkdir $HOME/.powder");
+		if (chdir(".powder") != 0)
+			err(1, "cannot cd to $HOME/.powder");
+	}
+
     // Call our main.
     gba_main();
     
