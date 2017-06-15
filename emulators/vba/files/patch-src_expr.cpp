--- src/expr.cpp.orig	2002-10-20 13:03:12 UTC
+++ src/expr.cpp
@@ -14,15 +14,12 @@
 
 #line 1 "expr.y"
 
-namespace std {  
+#include <sys/types.h>
 #include <stdio.h>
 #include <memory.h>
 #include <stdlib.h>
 #include <string.h>
-}
 
-using namespace std;
- 
 #include "System.h"
 #include "elf.h"
 #include "exprNode.h" 
