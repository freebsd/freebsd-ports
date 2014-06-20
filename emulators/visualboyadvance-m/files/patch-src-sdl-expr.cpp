--- src/sdl/expr.cpp.orig	2014-05-02 23:55:56.000000000 +0800
+++ src/sdl/expr.cpp	2014-05-02 23:56:07.000000000 +0800
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
