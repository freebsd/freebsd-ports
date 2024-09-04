--- include/Savitar/SceneNode.h.orig	2023-09-08 18:09:36 UTC
+++ include/Savitar/SceneNode.h
@@ -13,9 +13,11 @@
 
 #include <pugixml.hpp>
 
+#include "SavitarExport.h"
+
 namespace Savitar
 {
-class SceneNode
+class SAVITAR_EXPORT SceneNode
 {
 public:
     SceneNode() = default;
