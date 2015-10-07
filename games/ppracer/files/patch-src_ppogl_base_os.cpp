--- src/ppogl/base/os.cpp.orig	2015-09-19 23:30:52 UTC
+++ src/ppogl/base/os.cpp
@@ -32,6 +32,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <iostream>
+#include <cstring>
 
 #define MAX_BUFFER_SIZE 512
 
