--- lib/misc/util_misc.c.orig	2017-01-12 00:14:04.989252000 -0500
+++ lib/misc/util_misc.c	2017-01-12 00:14:12.099031000 -0500
@@ -307,7 +307,7 @@ Util_CanonicalPathsIdentical(const char 
    return (strcmp(path1, path2) == 0);
 #elif defined(_WIN32)
    return (_stricmp(path1, path2) == 0);
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
    return (strcasecmp(path1, path2) == 0);
 #else
    NOT_IMPLEMENTED();
