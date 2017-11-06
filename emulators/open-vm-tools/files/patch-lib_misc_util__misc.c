--- lib/misc/util_misc.c.orig	2017-02-24 22:15:37 UTC
+++ lib/misc/util_misc.c
@@ -307,7 +307,7 @@ Util_CanonicalPathsIdentical(const char 
    return (strcmp(path1, path2) == 0);
 #elif defined(_WIN32)
    return (_stricmp(path1, path2) == 0);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
    return (strcasecmp(path1, path2) == 0);
 #else
    NOT_IMPLEMENTED();
