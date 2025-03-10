--- include/Savitar/Scene.h.orig	2023-09-08 18:09:36 UTC
+++ include/Savitar/Scene.h
@@ -12,9 +12,11 @@
 
 #include <pugixml.hpp>
 
+#include "SavitarExport.h"
+
 namespace Savitar
 {
-class Scene
+class SAVITAR_EXPORT Scene
 {
 public:
     /**
