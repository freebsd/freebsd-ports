--- xwin.c.orig	2018-11-07 12:54:20 UTC
+++ xwin.c
@@ -4218,8 +4218,12 @@ void makeRasterFont(Display *dpy);
 #include <math.h>
 
 #include <fcntl.h>
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__)
 #include <copyfile.h>
+#elif defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/uio.h>
 #else
 #include <sys/sendfile.h>
 #endif
@@ -4238,9 +4242,14 @@ int OSCopyFile(const char* source, const
     }
 
     //Here we use kernel-space copying for performance reasons
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__)
     //fcopyfile works on FreeBSD and OS X 10.5+ 
     int result = fcopyfile(input, output, 0, COPYFILE_ALL);
+#elif defined(__FreeBSD__)
+    off_t bytesCopied = 0;
+    struct stat fileinfo = {0};
+    fstat(input, &fileinfo);
+    int result = sendfile(output, input, 0/*ofset*/, fileinfo.st_size, 0/*hdtr*/, &bytesCopied, 0/*flags*/);
 #else
     //sendfile will work with non-socket output (i.e. regular file) on Linux 2.6.33+
     off_t bytesCopied = 0;
