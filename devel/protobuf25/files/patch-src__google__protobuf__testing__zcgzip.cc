--- src/google/protobuf/testing/zcgzip.cc.orig	2014-09-30 22:46:34.571804492 +0800
+++ src/google/protobuf/testing/zcgzip.cc	2014-09-30 22:46:50.657816315 +0800
@@ -43,6 +43,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
+#include <unistd.h> // for STDOUT_FILENO
 
 #include <google/protobuf/io/gzip_stream.h>
 #include <google/protobuf/io/zero_copy_stream_impl.h>
