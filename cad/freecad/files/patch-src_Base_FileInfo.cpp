--- ./src/Base/FileInfo.cpp.orig	Sat Feb 24 11:44:54 2007
+++ ./src/Base/FileInfo.cpp	Sun Apr 22 00:02:40 2007
@@ -28,7 +28,7 @@
 #ifndef _PreComp_
 # include <assert.h>
 # include <stdio.h>
-# if defined (FC_OS_LINUX) || defined(FC_OS_CYGWIN)
+# if defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
 # include <unistd.h>
 # include <sys/stat.h>
 # elif defined (FC_OS_WIN32)
