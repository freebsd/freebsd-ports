--- libs/mpegtoraw.cc.orig	2001-02-15 13:43:40 UTC
+++ libs/mpegtoraw.cc
@@ -552,7 +552,7 @@ int  Mpegtoraw::getframesaved(void)
 #endif
 
 
-#include <iostream.h>
+#include <iostream>
 // Convert mpeg to raw
 bool Mpegtoraw::run(int frames)
 {
