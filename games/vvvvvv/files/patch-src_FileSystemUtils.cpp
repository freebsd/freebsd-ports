--- src/FileSystemUtils.cpp.orig	2024-01-10 16:27:34 UTC
+++ src/FileSystemUtils.cpp
@@ -1,10 +1,12 @@
 #include "FileSystemUtils.h"
 
+#include <errno.h>
 #include <physfs.h>
 #include <SDL.h>
 #include <stdarg.h>
 #include <stdio.h>
 #include <tinyxml2.h>
+#include <unistd.h>
 
 #include "Alloc.h"
 #include "BinaryBlob.h"
@@ -315,6 +317,12 @@ int FILESYSTEM_init(char *argvZero, char* baseDir, cha
     doesFontsDirExist = mount_pre_datazip(NULL, "fonts", "graphics/", fontsDir);
 
     /* Mount the stock content last */
+    if (assetsPath && access(assetsPath, R_OK) == -1) {
+        vlog_info("%s: %s", assetsPath, strerror(errno));
+        vlog_info("Trying %sdata.zip instead.", output);
+        assetsPath = NULL;
+    }
+
     if (assetsPath)
     {
         SDL_strlcpy(output, assetsPath, sizeof(output));
@@ -322,7 +330,7 @@ int FILESYSTEM_init(char *argvZero, char* baseDir, cha
     else
     {
         SDL_snprintf(output, sizeof(output), "%s%s",
-            basePath,
+            output,
             "data.zip"
         );
     }
