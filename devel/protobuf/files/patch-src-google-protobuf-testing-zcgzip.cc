--- src/google/protobuf/testing/zcgzip.cc.orig	2016-09-24 02:12:45 UTC
+++ src/google/protobuf/testing/zcgzip.cc
@@ -41,6 +41,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 #ifdef _WIN32
 #ifndef STDIN_FILENO
