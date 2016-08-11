--- include/babeltrace/compat/limits.h.orig	2016-07-28 12:52:51 UTC
+++ include/babeltrace/compat/limits.h
@@ -29,10 +29,11 @@
 
 #define BABELTRACE_HOST_NAME_MAX HOST_NAME_MAX
 
+/*
 #elif defined(__FreeBSD__)
 
 #define BABELTRACE_HOST_NAME_MAX MAXHOSTNAMELEN
-
+*/
 #elif defined(_POSIX_HOST_NAME_MAX)
 
 #define BABELTRACE_HOST_NAME_MAX _POSIX_HOST_NAME_MAX
