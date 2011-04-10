--- ./Modules/Compiler/GNU.cmake.orig	2011-02-15 20:47:27.000000000 +0300
+++ ./Modules/Compiler/GNU.cmake	2011-04-09 13:43:24.030760248 +0400
@@ -26,9 +26,9 @@
 
   # Initial configuration flags.
   set(CMAKE_${lang}_FLAGS_INIT "")
-  set(CMAKE_${lang}_FLAGS_DEBUG_INIT "-g")
+  set(CMAKE_${lang}_FLAGS_DEBUG_INIT "")
   set(CMAKE_${lang}_FLAGS_MINSIZEREL_INIT "-Os -DNDEBUG")
-  set(CMAKE_${lang}_FLAGS_RELEASE_INIT "-O3 -DNDEBUG")
+  set(CMAKE_${lang}_FLAGS_RELEASE_INIT "")
   set(CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT "-O2 -g")
   set(CMAKE_${lang}_CREATE_PREPROCESSED_SOURCE "<CMAKE_${lang}_COMPILER> <DEFINES> <FLAGS> -E <SOURCE> > <PREPROCESSED_SOURCE>")
   set(CMAKE_${lang}_CREATE_ASSEMBLY_SOURCE "<CMAKE_${lang}_COMPILER> <DEFINES> <FLAGS> -S <SOURCE> -o <ASSEMBLY_SOURCE>")
