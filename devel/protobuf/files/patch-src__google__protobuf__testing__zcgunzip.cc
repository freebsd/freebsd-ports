--- src/google/protobuf/testing/zcgunzip.cc.orig	2014-09-30 23:01:39.718744075 +0800
+++ src/google/protobuf/testing/zcgunzip.cc	2014-09-30 23:02:05.753740335 +0800
@@ -44,6 +44,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
+#include <unistd.h> // for STDOUT_FILENO
 
 #include <google/protobuf/io/gzip_stream.h>
 #include <google/protobuf/io/zero_copy_stream_impl.h>
