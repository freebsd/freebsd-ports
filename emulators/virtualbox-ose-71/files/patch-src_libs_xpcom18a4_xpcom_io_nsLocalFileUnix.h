--- src/libs/xpcom18a4/xpcom/io/nsLocalFileUnix.h.orig	2020-05-13 19:46:34 UTC
+++ src/libs/xpcom18a4/xpcom/io/nsLocalFileUnix.h
@@ -72,14 +72,6 @@
     #define STATFS statfs
 #endif
 
-// so we can statfs on freebsd
-#if defined(__FreeBSD__)
-    #define HAVE_SYS_STATFS_H
-    #define STATFS statfs
-    #include <sys/param.h>
-    #include <sys/mount.h>
-#endif
-
 class NS_COM nsLocalFile : public nsILocalFile
 {
 public:
