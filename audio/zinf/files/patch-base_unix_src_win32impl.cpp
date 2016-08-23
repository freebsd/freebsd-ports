--- base/unix/src/win32impl.cpp.orig	2003-09-16 20:34:55.000000000 +0300
+++ base/unix/src/win32impl.cpp
@@ -1,6 +1,7 @@
 #include <dlfcn.h>
 #include <dirent.h>
 #include <string>
+#include <cstring>
 #include <iostream>
 #include <stdio.h>
 #include <sys/stat.h>
