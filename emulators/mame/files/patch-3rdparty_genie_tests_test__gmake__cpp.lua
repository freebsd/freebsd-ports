--- 3rdparty/genie/tests/test_gmake_cpp.lua.orig	2023-04-25 15:19:25 UTC
+++ 3rdparty/genie/tests/test_gmake_cpp.lua
@@ -47,9 +47,9 @@ endif
   SILENT = @
 endif
 
-CC = gcc
-CXX = g++
-AR = ar
+CC ?= gcc
+CXX ?= g++
+AR ?= ar
 
 ifndef RESCOMP
   ifdef WINDRES
