--- src/Map.H.orig	1999-05-10 03:39:38 UTC
+++ src/Map.H
@@ -45,7 +45,7 @@ typedef struct _MapType {
 
 class Map {
 
-  friend NibblesArea;
+  friend class NibblesArea;
 
 public:
 
