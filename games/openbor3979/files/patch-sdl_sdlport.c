Store settings under ~/.openbor instead of current directory

--- sdl/sdlport.c.orig	2015-04-18 21:21:56 UTC
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
@@ -103,6 +105,16 @@ int main(int argc, char *argv[])
 #ifdef ANDROID
 	dirExists(rootDir, 1);
     chdir(rootDir);
+#else
+	if(!getenv("OPENBOR_USE_CURDIR"))
+	{
+		if (chdir(getenv("HOME")) != 0)
+			err(1, "cannot cd to $HOME");
+		if (mkdir(".openbor", 0755) != 0 && errno != EEXIST)
+			err(1, "cannot mkdir $HOME/.openbor");
+		if (chdir(".openbor") != 0)
+			err(1, "cannot cd to $HOME/.openbor");
+	}
 #endif
 	dirExists(paksDir, 1);
 	dirExists(savesDir, 1);
