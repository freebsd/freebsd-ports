--- libs/mpegtoraw.cc.orig	2001-02-15 14:43:40.000000000 +0100
+++ libs/mpegtoraw.cc	2013-09-23 12:11:46.000000000 +0200
@@ -552,7 +552,7 @@
 #endif
 
 
-#include <iostream.h>
+#include <iostream>
 // Convert mpeg to raw
 bool Mpegtoraw::run(int frames)
 {
