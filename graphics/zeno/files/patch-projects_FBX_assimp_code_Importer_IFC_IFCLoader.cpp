--- projects/FBX/assimp/code/Importer/IFC/IFCLoader.cpp.orig	2023-06-10 07:56:46 UTC
+++ projects/FBX/assimp/code/Importer/IFC/IFCLoader.cpp
@@ -52,11 +52,7 @@ ------------------------------------------------------
 #include <tuple>
 
 #ifndef ASSIMP_BUILD_NO_COMPRESSED_IFC
-#  ifdef ASSIMP_USE_HUNTER
 #    include <minizip/unzip.h>
-#  else
-#    include <unzip.h>
-#  endif
 #endif
 
 #include "IFCLoader.h"
