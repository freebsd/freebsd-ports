--- src/sdl/expr.cpp.orig	2016-08-13 15:20:47 UTC
+++ src/sdl/expr.cpp
@@ -90,14 +90,10 @@
 /* Copy the first part of user declarations.  */
 #line 1 "expr.ypp"
 
-namespace std {  
 #include <stdio.h>
 #include <memory.h>
 #include <stdlib.h>
 #include <string.h>
-}
-
-using namespace std;
  
 #include "../System.h"
 #include "../gba/elf.h"
