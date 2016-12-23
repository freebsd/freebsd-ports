Store settings under ~/.openbor instead of current directory

--- sdl/sdlport.c.orig	2013-12-29 14:05:10 UTC
+++ sdl/sdlport.c
@@ -6,6 +6,11 @@
  * Copyright (c) 2004 - 2014 OpenBOR Team
  */
 
+#include <errno.h>
+#include <unistd.h>
+#include <err.h>
+#include <sys/stat.h>
+
 #include "sdlport.h"
 #include "packfile.h"
 #include "ram.h"
@@ -92,6 +97,15 @@ int main(int argc, char *argv[])
 #ifdef ANDROID
 	dirExists(rootDir, 1);
     chdir(rootDir);
+#else
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
