--- framework/base/PGM.cpp.orig	2005-05-07 14:40:23 UTC
+++ framework/base/PGM.cpp
@@ -1,5 +1,6 @@
 #include "PGM.h"
 #include "PPM.h"
+#include <cstddef> // C++11 NULL
 #include <vector> // NULL definition
 
 namespace ProtoMol {
