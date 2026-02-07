--- src/opus.cc.orig	2020-11-08 09:32:46 UTC
+++ src/opus.cc
@@ -23,6 +23,7 @@
 
 #include <opustags.h>
 
+#include <sys/endian.h>
 #include <string.h>
 
 #ifdef __APPLE__
