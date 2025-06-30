commit 15841f187d2b208a6113d4e2d479d3af4275bb1c
Author: Simon Kelley <simon@thekelleys.org.uk>
Date:   Sun Jun 22 23:04:36 2025 +0100

    Fix issue with fast file-descriptor close on *BSD.
    
    This fixes a problem introduced in 8a5fe8ce6bb6c2bd81f237a0f4a2583722ffbd1c
    
    On BSD, fdescfs is normally mounted at /dev/fd. However
    if it is NOT mounted, devfs creates a directory at /dev/fd
    which contains (only) the file descriptors 0,1 and 2.
    
    Under these conditions, opendir() will succeed, and
    if we proceed we will fail to close extant
    file descriptors which should be closed.
    
    Check that there is a filesystem mounted at /dev/fd
    by checking that the device changes between /dev/fd
    and /dev. If if doesn't, fall back to the dumb path.
    
    Thanks to Roman Bogorodskiy for spotting the problem
    and helping with diagnosis.

--- src/util.c.orig	2025-03-14 15:09:35 UTC
+++ src/util.c
@@ -34,6 +34,10 @@
 #include <sys/utsname.h>
 #endif
 
+#ifdef HAVE_BSD_NETWORK
+#include <libgen.h>
+#endif
+
 /* SURF random number generator */
 
 static u32 seed[32];
@@ -831,9 +835,34 @@ void close_fds(long max_fd, int spare1, int spare2, in
 #endif
 
 #ifdef FDESCFS
-  DIR *d;
+  DIR *d = NULL;
   
-  if ((d = opendir(FDESCFS)))
+#  ifdef HAVE_BSD_NETWORK
+  dev_t dirdev = 0;
+  char fdescfs[] = FDESCFS; /* string must be writable */
+  struct stat statbuf;
+
+  /* On BSD, fdescfs is normally mounted at /dev/fd. However
+     if it is NOT mounted, devfs creates a directory at /dev/fd
+     which contains (only) the file descriptors 0,1 and 2.
+
+     Under these conditions, opendir() will succeed, and
+     if we proceed we will fail to close extant
+     file descriptors which should be closed.
+     
+     Check that there is a filesystem mounted at /dev/fd
+     by checking that the device changes between /dev/fd
+     and /dev. If if doesn't, fall back to the dumb path. */
+  
+  if (stat(fdescfs, &statbuf) != -1)
+    dirdev = statbuf.st_dev;
+
+  if (stat(dirname(fdescfs), &statbuf) != -1 &&
+      dirdev != statbuf.st_dev)
+#  endif
+    d = opendir(FDESCFS);
+      
+  if (d)
     {
       struct dirent *de;
 
