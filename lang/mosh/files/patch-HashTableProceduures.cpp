--- HashTableProceduures.cpp.orig	2008-08-16 14:52:38.000000000 +0400
+++ HashTableProceduures.cpp	2008-08-31 16:12:15.000000000 +0400
@@ -32,6 +32,8 @@
 #include "HashTableProceduures.h"
 #include "ProcedureMacro.h"
 
+#include <stdint.h>
+
 using namespace scheme;
 
 extern scheme::VM* theVM;
@@ -81,7 +83,7 @@
 int scheme::symbolHash(Symbol* symbol)
 {
     // we can use pointer as hash, because symbol is interned.
-    return reinterpret_cast<int>(symbol);
+    return reinterpret_cast<intptr_t>(symbol);
 }
 
 
