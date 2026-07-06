--- library/tulip-core/src/ParallelTools.cpp.orig	2026-06-17 13:56:19 UTC
+++ library/tulip-core/src/ParallelTools.cpp
@@ -103,7 +103,6 @@ static OpenMPDefaultOptions openMpDefaultOptions;
 #else
 
 #include <condition_variable>
-#include <tulip/tlphash.h>
 #include <tulip/IdManager.h>
 
 #endif
