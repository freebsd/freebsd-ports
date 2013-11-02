--- src/c++/pipes/impl/HadoopPipes.cc.orig	2013-07-23 00:26:40.000000000 +0200
+++ src/c++/pipes/impl/HadoopPipes.cc	2013-10-30 15:42:33.000000000 +0100
@@ -34,6 +34,7 @@
 #include <pthread.h>
 #include <iostream>
 #include <fstream>
+#include <unistd.h>
 
 #include <openssl/hmac.h>
 #include <openssl/buffer.h>
