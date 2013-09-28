--- ./sgp/MemMan.cc.orig	2013-09-28 16:08:40.756136684 +0200
+++ ./sgp/MemMan.cc	2013-09-28 16:09:05.355134574 +0200
@@ -5,6 +5,7 @@
 //		11sep96:HJH	- Creation
 //    29may97:ARM - Fix & improve MemDebugCounter handling, logging of
 //                    MemAlloc/MemFree, and reporting of any errors
+#include <new>
 #include <stdexcept>
 
 #include "Types.h"
