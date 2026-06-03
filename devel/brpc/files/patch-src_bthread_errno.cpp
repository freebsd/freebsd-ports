--- src/bthread/errno.cpp.orig	2026-02-23 02:11:29 UTC
+++ src/bthread/errno.cpp
@@ -35,7 +35,7 @@ int *bthread_errno_location() {
 int *bthread_errno_location() {
     return __errno_location();
 }
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
 
 extern int * __error(void);
 
