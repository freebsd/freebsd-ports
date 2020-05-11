--- src/SceneNode.cpp.orig	2020-05-11 21:53:40 UTC
+++ src/SceneNode.cpp
@@ -18,7 +18,7 @@
 
 #include "SceneNode.h"
 #include "Namespace.h"
-#include "../pugixml/src/pugixml.hpp"
+#include <pugixml.hpp>
 #include <iostream>
 using namespace Savitar;
 
