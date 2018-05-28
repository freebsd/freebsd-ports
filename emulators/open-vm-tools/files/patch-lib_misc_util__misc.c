--- lib/misc/util_misc.c.orig	2018-03-30 18:44:35 UTC
+++ lib/misc/util_misc.c
@@ -303,7 +303,7 @@ Util_CanonicalPathsIdentical(const char *path1,  // IN
    return (strcmp(path1, path2) == 0);
 #elif defined(_WIN32)
    return (_stricmp(path1, path2) == 0);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
    return (strcasecmp(path1, path2) == 0);
 #else
    NOT_IMPLEMENTED();
