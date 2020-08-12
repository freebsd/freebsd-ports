--- src/opus.cc.orig	2020-08-12 14:10:18 UTC
+++ src/opus.cc
@@ -24,6 +24,7 @@
 
 #include <opustags.h>
 
+#include <sys/endian.h>
 #include <string.h>
 
 #ifdef __APPLE__
