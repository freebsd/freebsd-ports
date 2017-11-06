--- src/libs/xpcom18a4/xpcom/io/nsLocalFileUnix.h.orig	2017-03-08 17:21:24.000000000 +0000
+++ src/libs/xpcom18a4/xpcom/io/nsLocalFileUnix.h	2017-03-08 22:53:39.572250000 +0000
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
