Store settings under ~/.openbor instead of current directory

--- sdl/sdlport.c.orig	2018-07-06 15:13:16 UTC
+++ sdl/sdlport.c
@@ -11,6 +11,8 @@
 #include "ram.h"
 #include "video.h"
 #include "menu.h"
+#include <sys/stat.h>
+#include <err.h>
 #include <time.h>
 #include <unistd.h>
 
@@ -135,6 +137,16 @@ int main(int argc, char *argv[])
     }
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
