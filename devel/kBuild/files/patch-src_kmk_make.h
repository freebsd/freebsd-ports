--- src/kmk/make.h.orig	2020-06-21 16:45:45 UTC
+++ src/kmk/make.h
@@ -472,7 +472,7 @@ extern int unixy_shell;
 #endif
 #ifdef SET_STACK_SIZE
 # include <sys/resource.h>
-struct rlimit stack_limit;
+extern struct rlimit stack_limit;
 #endif
 
 struct floc
