--- include/Savitar/Face.h.orig	2023-09-08 18:09:36 UTC
+++ include/Savitar/Face.h
@@ -4,9 +4,11 @@
 #ifndef FACE_H
 #define FACE_H
 
+#include "SavitarExport.h"
+
 namespace Savitar
 {
-class Face
+class SAVITAR_EXPORT Face
 {
 public:
     /**
