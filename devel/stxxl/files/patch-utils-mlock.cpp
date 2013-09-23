--- utils/mlock.cpp.orig	2010-08-31 16:22:17.000000000 +0400
+++ utils/mlock.cpp	2013-09-23 21:47:56.854519111 +0400
@@ -17,6 +17,7 @@
 #include <cstring>
 #include <iostream>
 #include <sys/mman.h>
+#include <unistd.h>
 
 int main(int argc, char ** argv)
 {
