--- sfark/sfarkextractor1.cpp.orig	2017-08-10 19:26:54 UTC
+++ sfark/sfarkextractor1.cpp
@@ -30,6 +30,8 @@
 #include "zlib.h"
 #include "stdint.h"
 
+#include <unistd.h>
+
 static const char * SfArkId = ".sfArk";
 
 SfArkExtractor1::SfArkExtractor1(const char * fileName) : AbstractExtractor(),
