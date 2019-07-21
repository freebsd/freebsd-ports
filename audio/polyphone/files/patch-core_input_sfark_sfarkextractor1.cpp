--- core/input/sfark/sfarkextractor1.cpp.orig	2019-07-16 14:22:06 UTC
+++ core/input/sfark/sfarkextractor1.cpp
@@ -30,8 +30,8 @@
 #include "zlib.h"
 #include "stdint.h"
 
-#ifdef Q_OS_MAC
-#include "unistd.h"
+#if defined(Q_OS_MAC) || defined(__FreeBSD__) || defined(__DragonFly__)
+#include <unistd.h>
 #endif
 
 static const char * SfArkId = ".sfArk";
