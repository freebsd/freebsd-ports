--- projects/FBX/assimp/code/Common/ZipArchiveIOSystem.cpp.orig	2023-06-10 07:56:46 UTC
+++ projects/FBX/assimp/code/Common/ZipArchiveIOSystem.cpp
@@ -52,11 +52,7 @@ ------------------------------------------------------
 #include <map>
 #include <memory>
 
-#ifdef ASSIMP_USE_HUNTER
 #  include <minizip/unzip.h>
-#else
-#  include <unzip.h>
-#endif
 
 namespace Assimp {
     // ----------------------------------------------------------------
