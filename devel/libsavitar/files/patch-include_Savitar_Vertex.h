--- include/Savitar/Vertex.h.orig	2023-09-08 18:09:36 UTC
+++ include/Savitar/Vertex.h
@@ -4,9 +4,11 @@
 #ifndef VERTEX_H
 #define VERTEX_H
 
+#include "SavitarExport.h"
+
 namespace Savitar
 {
-class Vertex
+class SAVITAR_EXPORT Vertex
 {
 public:
     /**
