--- include/Savitar/ThreeMFParser.h.orig	2023-09-08 18:09:36 UTC
+++ include/Savitar/ThreeMFParser.h
@@ -8,11 +8,13 @@
 #include <pugixml.hpp>
 
 #include <string>
+
+#include "SavitarExport.h"
 namespace Savitar
 {
 class Scene;
 
-class ThreeMFParser
+class SAVITAR_EXPORT ThreeMFParser
 {
 public:
     ThreeMFParser();
