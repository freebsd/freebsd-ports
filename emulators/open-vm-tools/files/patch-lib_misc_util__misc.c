--- lib/misc/util_misc.c.orig	2020-10-16 23:15:58 UTC
+++ lib/misc/util_misc.c
@@ -304,7 +304,7 @@ Util_CanonicalPathsIdentical(const char *path1,  // IN
    return (strcmp(path1, path2) == 0);
 #elif defined(_WIN32)
    return (_stricmp(path1, path2) == 0);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
    return (strcasecmp(path1, path2) == 0);
 #else
    NOT_IMPLEMENTED();
