--- common/rxmt_posix.c.orig	2011-05-09 01:25:33 UTC
+++ common/rxmt_posix.c
@@ -163,7 +163,7 @@ RxPackageGlobalDataDef *RxPackInitialize
    pthread_setspecific( ThreadIndex, retval );
 
    memset( retval, 0, sizeof(RxPackageGlobalDataDef) );
-   retval->MTMalloc = MTMalloc;
+   retval->MTMalloc = (void *(*)(const struct _tsd_t * ,long)) MTMalloc;
    retval->MTFree = MTFree;
    retval->MTExit = MTExit;
 
