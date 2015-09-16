--- Core/FileSystems/tlzrc.cpp.orig	2015-02-26 20:05:06 UTC
+++ Core/FileSystems/tlzrc.cpp
@@ -22,9 +22,6 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#if !defined(__SYMBIAN32__) && !defined(__MAC_10_6)
-#include <malloc.h>
-#endif
 
 #include "Common.h"
 
