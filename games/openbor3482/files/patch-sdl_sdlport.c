Store settings under ~/.openbor instead of current directory

--- sdl/sdlport.c.orig	2011-04-08 16:22:58 UTC
+++ sdl/sdlport.c
@@ -11,6 +11,9 @@
 #include "ram.h"
 #include "video.h"
 #include "menu.h"
+#include <sys/stat.h>
+#include <err.h>
+#include <unistd.h>
 
 #ifdef DARWIN
 #include <CoreFoundation/CoreFoundation.h>
@@ -83,6 +86,15 @@ int main(int argc, char *argv[])
 
 	packfile_mode(0);
 
+	if(!getenv("OPENBOR_USE_CURDIR"))
+	{
+		if (chdir(getenv("HOME")) != 0)
+			err(1, "cannot cd to $HOME");
+		if (mkdir(".openbor", 0755) != 0 && errno != EEXIST)
+			err(1, "cannot mkdir $HOME/.openbor");
+		if (chdir(".openbor") != 0)
+			err(1, "cannot cd to $HOME/.openbor");
+	}
 	dirExists(paksDir, 1);
 	dirExists(savesDir, 1);
 	dirExists(logsDir, 1);
