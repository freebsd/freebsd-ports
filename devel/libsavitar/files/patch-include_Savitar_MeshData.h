--- include/Savitar/MeshData.h.orig	2023-09-08 18:09:36 UTC
+++ include/Savitar/MeshData.h
@@ -14,9 +14,11 @@
 
 #include <pugixml.hpp>
 
+#include "SavitarExport.h"
+
 namespace Savitar
 {
-class MeshData
+class SAVITAR_EXPORT MeshData
 {
 public:
     /**
