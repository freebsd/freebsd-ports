--- src/MeshData.cpp.orig	2020-05-11 21:53:20 UTC
+++ src/MeshData.cpp
@@ -17,7 +17,7 @@
  */
 
 #include "MeshData.h"
-#include "../pugixml/src/pugixml.hpp"
+#include <pugixml.hpp>
 #include <cstring>
 #include <iostream>
 #include <stdexcept> //For std::runtime_error.
