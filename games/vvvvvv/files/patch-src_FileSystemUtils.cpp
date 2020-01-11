--- src/FileSystemUtils.cpp.orig	2020-01-10 22:11:00 UTC
+++ src/FileSystemUtils.cpp
@@ -73,6 +73,12 @@ int FILESYSTEM_init(char *argvZero)
 #ifdef _WIN32
 	strcpy(output, PHYSFS_getBaseDir());
 	strcat(output, "data.zip");
+#elif defined(__FreeBSD__)
+	PLATFORM_getOSDirectory(output);
+	if (strlcat(output, "data.zip", sizeof(output)) >= sizeof(output)) {
+		puts("Cannot find location for data.zip\n");
+		return 0;
+	}
 #else
 	strcpy(output, "data.zip");
 #endif
