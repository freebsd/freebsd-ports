--- src/google/protobuf/message.cc.orig	2012-03-14 23:11:12.000000000 +0800
+++ src/google/protobuf/message.cc	2012-03-14 23:11:26.000000000 +0800
@@ -32,6 +32,7 @@
 //  Based on original Protocol Buffers design by
 //  Sanjay Ghemawat, Jeff Dean, and others.
 
+#include <iostream>
 #include <stack>
 #include <google/protobuf/stubs/hash.h>
 
