--- src/FileSystemUtils.cpp.orig	2021-12-22 13:20:25 UTC
+++ src/FileSystemUtils.cpp
@@ -1,3 +1,4 @@
+#include <errno.h>
 #include <iostream>
 #include <iterator>
 #include <physfs.h>
@@ -154,6 +155,12 @@ int FILESYSTEM_init(char *argvZero, char* baseDir, cha
 	}
 
 	/* Mount the stock content last */
+	if (assetsPath && access(assetsPath, R_OK) == -1) {
+		printf("%s: %s\n", assetsPath, strerror(errno));
+		printf("Trying %sdata.zip instead.\n", output);
+		assetsPath = NULL;
+	}
+
 	if (assetsPath)
 	{
 		SDL_strlcpy(output, assetsPath, sizeof(output));
@@ -161,7 +168,7 @@ int FILESYSTEM_init(char *argvZero, char* baseDir, cha
 	else
 	{
 		SDL_snprintf(output, sizeof(output), "%s%s",
-			basePath,
+			output,
 			"data.zip"
 		);
 	}
